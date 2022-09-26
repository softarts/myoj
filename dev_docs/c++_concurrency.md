# sync 
## Spinlock
没有标准实现，使用boost/tbb
```
#include <boost/atomic.hpp>
class spinlock {
private:
  typedef enum {Locked, Unlocked} LockState;
  boost::atomic<LockState> state_;
public:
  spinlock() : state_(Unlocked) {}
  void lock()
  {
    while (state_.exchange(Locked, boost::memory_order_acquire) == Locked) {
      /* busy-wait */
    }
  }
  void unlock()
  {
    state_.store(Unlocked, boost::memory_order_release);
  }
};
```
使用一个atomic来做busy_wait,tbb中的实现更复杂。

使用:注意在函数中必须初始化，而作为全局变量和成员则不需要，因为C++有默认初始化？
```
#include "boost/smart_ptr/detail/spinlock.hpp"
int loop_spin(bool inc, int limit) {
    std::cout << "Started " << inc << " " << limit << std::endl;
    boost::detail::spinlock mu = BOOST_DETAIL_SPINLOCK_INIT;
    for (int i = 0; i < limit; ++i) {
        std::lock_guard<boost::detail::spinlock> guard(mu);        
        if (inc) {
            ++value;
        }
        else {
            --value;
        }
    }
    return 0;
}
```

## condition variable
[http://www.cppblog.com/Solstice/archive/2015/10/30/203094.html](http://www.cppblog.com/Solstice/archive/2015/10/30/203094.html)


## mutex
### lock_guard 和unique_lock
mutex 有try_lock,lock,unlock成员函数,但往往不会直接使用，而是通过RAII的模板类:
```
std::lock_guard<std::mutex> guard(some_mutex);
```

try_lock 和adopt_lock结合，用于尝试性的lock
std::lock_guard<std::timed_mutex> lg(m,std::adopt_lock)  
std::unique_lock()和lock_guard()没有太大差别，前者提供了更多的精细控制(boost类同)，如owns_lock(), release(),bool()等，可以传递lock，从而在该lock的范围之外继续执行保护代码??拥有mutex变量，所以size相对大一点(own_lock),可以灵活的unlock，又再lock ??

但基本上都支持同时锁多个对象，timed_mutex,recursive_mutex等

### unique_lock 锁住两个对象 
使用unique_lock
```
void transfer(Box &from, Box &to, int num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);
 
    // lock both unique_locks without deadlock
    std::lock(lock1, lock2); 
    from.num_things -= num;
    to.num_things += num; 
    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}
```
锁定多个mutex，在两个资源中传递数据
```
std::lock（m1,m2）
std::lock_guard<std::mutex> guard1(m1,std::adopt_lock);
std::lock_guard<std::mutex> guard1(m1,std::adopt_lock);
```

或者用try_lock
```
void lock2Items() {
  std::mutex m1,m2;
  int idx = std::try_lock(m1,m2);
  //-1 on success, or 0-based index value of the object that failed to lock.
  if (idx<0) {
      std::lock_guard<std::mutex> lk1(m1,std::adopt_lock);
      std::lock_guard<std::mutex> lk2(m2,std::adopt_lock);
  } else {
      std::cerr << "unable to lock mutex m" << idx+1 <<endl;
  }
}
```

### defer,adopt_lock,try_to_lock
defer_lock_t	do not acquire ownership of the mutex, 和unique_lock搭配，初始化时不取得ownership
try_to_lock_t	try to acquire ownership of the mutex without blocking
adopt_lock_t	assume the calling thread already has ownership of the mutex

### try_lock和超时try_lock
```
void tryLock() {
    std::timed_mutex m;
    if (m.try_lock_for(std::chrono::seconds(1))) {
        std::lock_guard<std::timed_mutex> lg(m,std::adopt_lock);
    } else {
        // unable to get lock;
    }
}
```

无超时
```
void tryLock() {
    std::mutex m;
    while (m.try_lock()==false) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::lock_guard<std::mutex> lk(m, std::adopt_lock);  // 前面已经取得ownership了
    // do something
}
```


### 递归锁recursive_lock


##	promise & futures
futures 是一种期望,有unique 和shared future两种，与shared_ptr类似，shared future可以关联多个事件
promise不可以copy
每一个promise都和一个shared state关联，用来存储value/exception(从而使shared state的状态变为ready),供关联的future稍后读取





### promise线程同步
```
void promise_thread_sync_flag(std::promise<void> barrier)  
{  
  std::this_thread::sleep_for(std::chrono::seconds(1));  
  barrier.set_value();  
}  
  
void test_promise_sync() {  
  std::promise<void> barrier;  
  std::future<void> barrier_future = barrier.get_future();  
  std::thread new_work_thread(promise_thread_sync_flag, std::move(barrier));  
  barrier_future.wait();  // promise，等待线程里的那个set_value
  cout << "thread has set value" << endl;  
  new_work_thread.join();  
}
```

### 捕捉异步任务返回的异常 via future
```
static void promise_store_value(std::promise<int> &barrier)
{
    try {
        // barrier.set_value(1); // set only once
        throw std::system_error(EACCES,std::generic_category(),"syserr");

    } catch (...) {
        barrier.set_exception(std::current_exception());
    }
}

void test_promise_exception()
{
    std::promise<int> barrier;
    std::thread t1(promise_store_value, std::ref(barrier));
    std::cout << "waiting promise data...\n";
    //barrier_future.wait();
    std::future<int> barrier_future = barrier.get_future();

    try {
        std::cout << "result: " << barrier_future.get() << '\n';
    } catch (const std::exception &e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "caught some error " << endl;
    }

    t1.join();
}
```


    
## Future/async
future是一个异步返回对象，用于取得线程的返回值,只有move ctor
- 通过async默认参数启动的func，立即，或者稍等启动，启动时间不可控，不确定是否在独立的线程里启动
- 调用future.get的时候，如果已结束，那么取得返回结果，如果正在执行，那么等待，如果尚未开始，那么启动一个同步调用(**不确定是否在独立线程**)
- 拉开async和get之间的距离，理论上可以优化并发的可能性
- 为一个future<>只能调用一次get()，之后这个future就处于不可用状态了，可用valid()查看。

### shared state
首先需要理解shared state,它是保存在堆上的一个带引用计数的object，允许启动任务的promise, packaged_task, async和处理结果的future/shared_future进行沟通。


### 如果指定了deferred,那么必须通过get()来取得运行结果(调用get的线程)
lazy evaluation
wait & get 都可以强制启动task，但是wait_for/until 不可以，如果policy是deferred，他会立即返回
```
int print_char(char c)  
{   
  cout << "thread ID " << this_thread::get_id() << endl;  
  default_random_engine dre(c);  
  uniform_int_distribution<int> id(10, 1000);  
  // loop to print character after a random period of time  
  for (int i = 0; i < 10; ++i)  
  {  
    this_thread::sleep_for(chrono::milliseconds(id(dre)));  
    cout.put(c).flush();  
  }  
  return c;  
}  
// defered 必须通过get来取得异步任务结果
void test_future1() {
    cout << "test_future1 thread ID " << this_thread::get_id() << endl;
    std::future<int> f1 = std::async(std::launch::deferred,
                                     [] { return print_char('.'); }); // move ctor
    //wait & get can force to start task
    // but wait_for() doesn't

    future_status fs1 = f1.wait_for(chrono::seconds(10));
    if (fs1 == future_status::deferred) {
        cout << " deferred =" << int(fs1) << endl;
    }
    this_thread::sleep_for(chrono::seconds(10));
    cout << "sleep 10s complete" <<endl;
    //f1.wait();
    //f1.get();//wait?
}
```

### launch::async返回的future

**简单讲，launch::async返回的future，其dtor会隐式的等待函数执行结束，意味着函数必须被执行**

反对意见
[http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3451.pdf](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3451.pdf)
[http://scottmeyers.blogspot.com/2013/03/stdfutures-from-stdasync-arent-special.html](http://scottmeyers.blogspot.com/2013/03/stdfutures-from-stdasync-arent-special.html)

- async语句会返回一个future，用来保存async任务的结果，这个future是个临时对象
- 在async语句结束的时候，临时future的dtor会被调用
- 可以把临时future move或者绑定到另一个生命周期更长的future上
- 无论哪种future，在dtor的时候都会block等待异步任务的执行，这意味着异步任务一定会被执行
- 只针对async创建的shared_state所关联的future


For std::launch::async, the standard states that the returned future's destructor (~future) will block until the task is complete（MSVC违反此规定？）
以上有争论（取消dtor中的隐式join），然而C++14中仍然是这样实现的
[https://stackoverflow.com/questions/23455104/why-is-the-destructor-of-a-future-returned-from-stdasync-blocking](https://stackoverflow.com/questions/23455104/why-is-the-destructor-of-a-future-returned-from-stdasync-blocking)

[https://stackoverflow.com/questions/30535028/is-stdasync-guaranteed-to-be-called-for-functions-returning-void](https://stackoverflow.com/questions/30535028/is-stdasync-guaranteed-to-be-called-for-functions-returning-void)

**因为这种情况实际上是串行执行的，因为每个async产生的temporary future object 都要调用dtor(从而是block等待该异步任务结束)**
[https://en.cppreference.com/w/cpp/thread/async](https://en.cppreference.com/w/cpp/thread/async)
```
void test_future3() {  
  cout << "thread ID " << this_thread::get_id() << endl;  
  std::async(std::launch::async, [] { return print_char('.'); });  
  std::async(std::launch::async, [] { return print_char('+'); });  
}
```

### 不指定launch策略
不指定策略的话， 取决于runtime来决定如何运行异步任务,多数情况下都不是deferred，但不保证，需要预先检查。 **只有不是deferred，才可以用wait去等待任务结果**
```
void test_future2() {  
  cout << "test_future2 thread ID " << this_thread::get_id() << endl;  
  
  std::future<int> f1 = std::async([] { return print_char('.'); });  
  std::future<int> f2 = std::async([] { return print_char('+'); });  
  if (f1.wait_for(chrono::seconds(0)) ==future_status::deferred) {  
        cout << "f1 is deferred policy" << endl;  
  }
  if (f2.wait_for(chrono::seconds(0)) ==future_status::deferred) {  
        cout << "f2 is deferred policy" << endl;  
  }  
  
  if (f1.wait_for(chrono::seconds(0)) !=future_status::deferred ||  
      f2.wait_for(chrono::seconds(0)) !=future_status::deferred) {  
      while (f1.wait_for(chrono::seconds(0)) != future_status::ready &&  
             f2.wait_for(chrono::seconds(0)) != future_status::ready ) {  
        this_thread::yield();  
      }  
  }  
  
  // at least one task complete  
  cout.put('\n').flush();  
  cout << "at least one task complete" << endl;  
  try {  
    f1.get();  
    f2.get();  
  } catch (const exception &e) {  
    cout << "\nEXCEPTION:" << e.what() << endl;  
  }  
    cout << "\n done" << endl;    
}
```

### shared_future

### 单线程环境
get()

```
#include <future>
int fib(int n)
{
    if (n < 3) return 1;
    else return fib(n - 1) + fib(n - 2);
}

void test_future()
{
    auto f1 = std::async(fib, 10);
    auto f2 = std::async(fib, 11);
    std::cout << "waiting...\n";
    f1.wait();  // wait for task execution
    f2.wait();
    std::cout << "f1: " << f1.get() << '\n';
    std::cout << "f2: " << f2.get() << '\n';
}
```
### wait/wait_for/wait_until

### 思考
2022/8/23
C++中缺乏executor 这类, 参考 boost asio 之类的实现，io怎么驱动的
epoll, 

## packaged_task
packaged_task是一个更低层的API用来实现async的，没什么特别之处

- 需要主动invoked才能启动
- 可以通过future.get取得返回结果
- 可以和thread一起(实则上就是看作一个func传递给thread?)

```
void task_lambda()
{
    std::packaged_task<int(int,int)> task([](int a, int b) {
        cout << "lambda thread ID " << this_thread::get_id() << endl;
        return std::pow(a, b);
    });
    std::future<int> result = task.get_future();
    cout << "main thread ID " << this_thread::get_id() << endl;
    task(2, 9); // 必须手动触发
    std::cout << "task_lambda:\t" << result.get() << '\n';
}
```

packaged_task.get_future() 返回的future指向的shared_state不是由async创建的,所以不会在dtor中block异步任务？(**实在没看懂EMC item 38**)


# 线程
## pthread_create
比较旧的做法
```
void *myThreadFun(void *vargp) 
{ 
    sleep(1); 
    printf("Printing GeeksQuiz from Thread \n"); 
    return NULL; 
} 
   
int main() 
{ 
    pthread_t thread_id; 
    printf("Before Thread\n"); 
    pthread_create(&thread_id, NULL, myThreadFun, NULL); 
    pthread_join(thread_id, NULL); 
    printf("After Thread\n"); 
    exit(0); 
}
```

## std::thread

如果thread对象还能够joinable的时候就析构了对象，会调用terminate/abort来中止线程，猜测，需要detach,或者windows平台上使用_set_abort_behavior(0, _WRITE_ABORT_MSG);来捕捉abort信号(linux平台显然就是SIGABORT)
```
void create_thread()
{
    std::thread t(do_work2, 10);  // dtor thread obj trigger abort/terminate
}
```
### thread destructor [thread.thread.destr] ~thread();
If joinable(), calls std::terminate(). Otherwise, has no effects.
[ Note: Either implicitly detaching or joining a joinable() thread in its destructor could result in difficult to debug correctness (for detach) or performance (for join) bugs encountered only when an exception is raised. Thus the pro grammer must ensure that the destructor is never executed while the thread is still joinable. — end note ]


然而boost却没有这个问题,可以在局部函数中启动线程,析构后线程仍然在运行.

没有copy ctor
std::thread t1(xxx);
std::thread t2 = t1;//错误

### this_thread
```
yield()
sleep_for(chrono::millseconds())
sleep_for(1s)
```

##	Atomic 原子操作
### 使用
禁止了atomic class 的copy ctor(参数是本类型&)和assignment(不禁止其模板类型)，可参见c++ concurrency in action一书的描述
```
std::atomic_flag f=ATOMIC_FLAG_INIT
std::atomic<int> x(0),y(0),z(0); 
std::atomic<bool> go(false); 或者go=true
x.load(std::memory_order_relaxed);
x.store(i+1,std::memory_order_relaxed);
++,--,+=,-=,&=, fetch_and 都是重载为原子操作
```
###	C++中读写int 变量是否原子操作
MSDN
https://msdn.microsoft.com/en-us/library/ee418650(v=vs.85).aspx

>On all modern processors, you can assume that reads and writes of naturally aligned native types are atomic. As long as the memory bus is at least as wide as the type being read or written, the CPU reads and writes these types in a single bus transaction, making it impossible for other threads to see them in a half-completed state. 
>
>On x86 and x64 there, is no guarantee that reads and writes larger than eight bytes are atomic. This means that 16-byte reads and writes of streaming SIMD extension (SSE) registers, and string operations, might not be atomic.
>
>Reads and writes of types that are not naturally aligned—for instance, writing DWORDs that cross four-byte boundaries—are not guaranteed to be atomic. The CPU may have to do these reads and writes as multiple bus transactions, which could allow another thread to modify or see the data in the middle of the read or write.
>长度小于等于cpu/memory bus而且字节对齐的变量的读写是atomic 操作

Intel
>This recommendation is architecture-specific. It is true for x86 & x86_64 (in a low-level programming). You should also check that compiler don't reorder your code. You can use "compiler memory barrier" for that.
>Low-level atomic read and writes for x86 is described in Intel Reference manuals "The Intel® 64 and IA-32 Architectures Software Developer’s Manual" Volume 3A  http://www.intel.com/Assets/PDF/manual/253668.pdf  , section 8.1.1
>根据IA64手册，X86_64架构下，不跨越cacheline的8byte读写是原子的，如果你有个指针，没有跨越cacheline，那么多线程对这个指针的复制和读取都是不需要加锁的，可以保证原子的读到这8byte，但是对于指针强制类型转换或者c++ placement new等情况，可能无法保证struct或class里的成员不跨越cacheline，

**Guaranteed Atomic Operations**

The Intel486 processor (and newer processors since) guarantees that the following basic memory operations will always be carried out atomically:

读或写一个byte,word(16bit),32bit,64bit 对齐的变量都是原子操作
```
Reading or writing a byte
Reading or writing a word aligned on a 16-bit boundary
Reading or writing a doubleword aligned on a 32-bit boundary
The Pentium processor (and newer processors since) guarantees that the following additional memory operations will always be carried out atomically:
Reading or writing a quadword aligned on a 64-bit boundary
16-bit accesses to uncached memory locations that fit within a 32-bit data bus
The P6 family processors (and newer processors since) guarantee that the following additional memory operation will always be carried out atomically:
Unaligned 16-, 32-, and 64-bit accesses to cached memory that fit within a cache line,
```
**没有对齐的变量，但如果在cacheline里面也是原子操作。**

This document also have more description of atomically for newer processors like Core2. Not all unaligned operations will be atomic.

Other intel manual recommends this white paper:
http://software.intel.com/en-us/articles/developing-multithreaded-applications-a-platform-consistent-approach/

与MSDN的讲法基本一致,而且有些unaligned 的地址落在cache line的话也是atomic, 但如果不是Intel X86处理器，则不确定.因为C++ 标准并没有明确指出，所以还是该使用标准的atomic 类型，这帮我们处理了不同平台的情况.
```
*counter = 0; // this is atomic on most platforms
*counter++;   // this is NOT atomic on most platforms
```

对于JAVA
实现对普通long与double的读写不要求是原子的（但如果实现为原子操作也OK,实现对volatile long与volatile double的读写必须是原子的（没有选择余地）,
允许没有被volatile修饰的long 和double 分成2个32bit来实现。经过测试，主流的64bit JVM都是实现了原子读写，32bit则不一定，可以通过开关



### 用于实现引用计数
(cracking coding interview) p224

###	内存顺序
在std::thread::store写入函数的第二个参数可以指派内存顺序.
```
枚举值	规则
memory_order_relaxed	不对执行顺序做任何保证
memory_order_consume	本线程所有后续有关本操作的必须在本操作完成后执行
memory_order_acquire	本线程所有后续的读操作必须在本条操作完成才能执行
memory_order_release	本线程所有之前的写操作完成后才执行本操作
memory_order_acq_rel	同时包含acquire和release
memory_order_seq_cst	全部顺序执行

memory_order_relaxed表示松散内存模型，指可以任由编译器重排序或者处理器乱序执行代码.
memory_order_acquire表示在当前线程所有后续的读操作都必须在本原子操作完成后执行.
memory_order_release表示所有之前的写操作完成后才能执行本条原子操作.
memory_order_acq_rel表示同时memory_order_acquire和memory_order_release具有.
memory_order_consume表示本线程中，所有后续的有关本原子类型的操作，都必须在本条原子操作完成之后执行.
memory_order_seq_cst全部存取都按照顺序执行.默认方式
```

https://bartoszmilewski.com/2008/12/01/c-atomics-and-memory-ordering/
很难找到一个能够实现happen-before的例子，但并不等于没有

test_and_set 设置为true并返回previous value

可以利用atomic_flag创建自旋锁 TODO

is_lock_free()用于判断atomic的实现是基于internal lock还是lockfree,对于通过atomic<>实现的自由类型，需要自行实现is_lock_free()函数
store(),load(),
operator T() const volatile noexcept;
operator T() const noexcept;
atomic<int> operator += 实际上调用fetch_add()，后者可以指定memory order.

T exchange (T val, memory_order sync = memory_order_seq_cst) volatile noexcept;
T exchange (T val, memory_order sync = memory_order_seq_cst) noexcept;

读取并修改被封装的值，exchange 会将 val 指定的值替换掉之前该原子对象封装的值，并返回之前该原子对象封装的值，整个过程是原子的(因此exchange 操作也称为 read-modify-write 操作)。val自身并没有改变

bool compare_exchange_weak (T& expected, T val,memory_order sync = memory_order_seq_cst) volatile noexcept;
比较并交换被封装的值(weak)与参数 expected 所指定的值是否相等，如果：

相等，则用 val 替换原子对象的旧值。
不相等，则用原子对象的旧值替换 expected ，因此调用该函数之后，如果被该原子对象封装的值与参数 expected 所指定的值不相等，expected 中的内容就是原子对象的旧值。

在某些缺乏single compare_exchange 指令的平台上，可能比较成功却不能存储成功(返回false)
因此需要在loop中处理compare_exchange_weak():
例如
Bool expected = false;
While (!b.compare_exchange_weak(expected,true) && !expected)


# Other
## singleton

**2020更新**

2020/05 - lock 是一种release-acquire语义，表示在这之前的所有读写都已完成，但是对于double check仍然有漏洞，需要volatile或者atomic来控制最后instance的读写，或者使用一个temp变量)
正确的实现,JAVA中使用volatile
```
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}
或者
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_acquire);
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            m_instance.store(tmp, std::memory_order_release);
        }
    }
    return tmp;
}
或者
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load();
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load();
        if (tmp == nullptr) {
            tmp = new Singleton;
            m_instance.store(tmp);
        }
    }
    return tmp;
}
SC atomics are really similar to volatile variables in Java 5+.
```

**旧**
2015-06-16
MCD 提及了下面这种方式在现代CPU上不安全，实际上我认为由于lock的存在，应该是安全的，不会发生reorder.


另一种实现，muduo c2.5 pthread_once保证只调用init一次。或者call_once
pthread_once_t＝ PTHREAD_ONCE_INIT

2010/01/07
保证一个类仅有一个实例,C++实现: 让类自身保存它的唯一实例(用static),再用一个static 函数instance()用以创建实例,下面这种必须用锁来保证线程安全。属于Lazy-initialization
```
Singleton* Singleton::getInstance()
 {
     if(NULL == m_instance)
     {
         Lock();//借用其它类来实现，如boost
         if(NULL == m_instance)
         {
             m_instance = new Singleton;
         }
         UnLock();
     }
     return m_instance;
 }
```

Eager-initialization则可以在main()之前就初始化所有静态变量，是线程安全的。直接定义全局静态变量？


http://stackoverflow.com/questions/1661529/is-meyers-implementation-of-singleton-pattern-thread-safe
is  Meyers implementation of singleton thread safe?
C++11中是安全的，保证静态变量的初始化，这个变量必然要调用构造函数.
If control enters the declaration concurrently while the variable is being initialized, theconcurrent execution shall wait for completion of the initialization.


对于后面的验证代码，使用gcc 4.3.4编译
```
#0  0x00007ffff718b789 in syscall () from /lib64/libc.so.6
#1  0x00007ffff7b3bdfb in __cxa_guard_acquire () from /usr/lib64/libstdc++.so.6
#2  0x0000000000400b19 in SingletonInside::getInstance (param=0) at singleton.cpp:19
#3  0x0000000000400a99 in createSingleton (param=0x7fffffffe390) at singleton.cpp:31
#4  0x00007ffff74337b6 in start_thread () from /lib64/libpthread.so.0
#5  0x00007ffff718ed6d in clone () from /lib64/libc.so.6
#6  0x0000000000000000 in ?? ()
```

说明gcc 4.3.4内部默认支持静态变量初始化的thread-safe了，可以认为某些C++0x的特性在GCC中已经支持了.据说使用-fno-threadsafe-statics 可以禁止这个特性
```
static guard;
if (!guard.first_byte) {
  if (__cxa_guard_acquire (&guard)) {
  bool flag = false;
  try {
    // Do initialization.
    flag = true; __cxa_guard_release (&guard);
    // Register variable for destruction at end of program.
  } catch {
    if (!flag) __cxa_guard_abort (&guard);
  }
}
```
以上是静态变量初始化的实现

在gcc4.8中反而看不到这个cxa_guard,可能已不需要？
补充一个用于保护静态变量初始化的lock

```
int__cxxabiv1::__cxa_guard_acquire(uint64_t* guard_object)
{
    // Double check that the initializer has not already been run
    if ( initializerHasRun(guard_object) )
      return 0;

    // We now need to acquire a lock that allows only one thread
    // to run the initializer.  If a different thread calls
    // __cxa_guard_acquire() with the same guard object, we want 
    // that thread to block until this thread is done running the 
    // initializer and calls __cxa_guard_release().  But if the same
    // thread calls __cxa_guard_acquire() with the same guard object,
    // we want to abort.  
    // To implement this we have one global pthread recursive mutex 
    // shared by all guard objects, but only one at a time.  

    int result = ::pthread_mutex_lock(guard_mutex());
    if ( result != 0 ) {
            abort_message("__cxa_guard_acquire(): pthread_mutex_lock "
    "failed with %d\n", result);
        }
    // At this point all other threads will block in __cxa_guard_acquire()

    // Check if another thread has completed initializer run
    if ( initializerHasRun(guard_object) ) {
    int result = ::pthread_mutex_unlock(guard_mutex());
    if ( result != 0 ) {
                abort_message("__cxa_guard_acquire(): pthread_mutex_unlock "
    "failed with %d\n", result);
            }
    return 0;
}

// The pthread mutex is recursive to allow other lazy initialized
// function locals to be evaluated during evaluation of this one.
// But if the same thread can call __cxa_guard_acquire() on the 
// *same* guard object again, we call abort();
    if ( inUse(guard_object) ) {
        abort_message("__cxa_guard_acquire(): initializer for function "
"local static variable called enclosing function\n");
}

// mark this guard object as being in use
    setInUse(guard_object);

// return non-zero to tell caller to run initializer
return 1;
}
```

用于验证的代码
```
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

class SingletonInside
 {
  private:
      SingletonInside(int param){
        int x = 0;
        for (int i = 0 ; i <10; i++ ) {
          fprintf(stdout, "I am in ctor %d\n",param);
          sleep(1);
        }
      }
  public:
      static SingletonInside* getInstance(int param)
      {
          // Lock(); // not needed after C++0x
         static SingletonInside instance(param);
         //UnLock(); // not needed after C++0x
         return &instance; 
      }
      void test()
      {
        fprintf(stdout, "called test\n");
      }
 };


void *createSingleton(void *param) {
  SingletonInside *ptr = SingletonInside::getInstance(*((int*)param));
  ptr->test();
}

int main() {
  pthread_t handle[2];
  int param[2] = {0,1};
  for (int i = 0; i < 2; i++) {
    if(pthread_create(&handle[i], NULL, createSingleton, &param[i])) {
      fprintf(stderr, "Error creating thread %d\n", i);
      return 1;
    }
  }

  for (int i = 0; i < 2; i++) {
    pthread_join(handle[i], NULL);
    fprintf(stdout, "thread %d exit\n", i);
  }
}
```
片段
```
class SingletonInside
 {
  private:
      SingletonInside(){}
  public:
      static SingletonInside* getInstance()
      {
        Lock(); // not needed after C++0x
        static SingletonInside instance;
        UnLock(); // not needed after C++0x
        return instance; 
     }
 };
 ```
