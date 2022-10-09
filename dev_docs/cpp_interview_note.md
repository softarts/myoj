# C++ basic
ctor,copy ctor, copy assignment, move ctor, move assignment
exception 机制

bit field
```
struct S1{
    int i:8;
    char j:4;
    int a:4; //这个无论有没有都不影响
    double b;
};
```
sizeof(S1) = 16,因为最后的b是8bytes，必须对齐8bytes,所以前面凑够8 bytes

##	数学公式
组合公式 C(5,2) = 5!/((5-2)!*2!) = 
C(N,M) = N!/((N-M)!*M!),当M为2的时候，可以简化为N*(N-1)/2

全排列 排列的定义：从n个不同元素中，任取m(m≤n,m与n均为自然数,下同）个元素按照一定的顺序排成一列，叫做从n个不同元素中取出m个元素的一个排列；从n个不同元素中取出m(m≤n）个元素的所有排列的个数，叫做从n个不同元素中取出m个元素的排列数，用符号 A(n,m）表示。
P(n,m) = n!/(n-m)! 当n=m时为factorial 阶乘

长度为n的数组，有多少个子序列
1+2+3+…+n = n*(n+1)/2

## 指针和数组

二维数组
int arr[row][col]={{row0},{row1}}
int arr[][2] = {(1,2,3),(4,5,6)}  这种方式实质上是逗号运算符，等于{3,6}
2维数组是无法转换为double pointer的，因为他们的内存完全不一样，二维数组实际上内存是连续的

指针数组和数组指针
int *var[5] => var[5] is array, int * is type, 即一个数组，元素是指针
int [][] ->int** ？

考察const char * 和char * const的区别，给一段程序，判断错在哪里
从右往左读
char *const 常量指针，指向char
const char *指针， 指向常量char


delete[]
C++primer, p630,缺少[]可能导致只在首元素上调用dtor,尽管释放的内存量可能是正确的,delete[]为每一个成员调用了dtor.

C++中如何分配字符串空间
```
char str1[] = "hello world";
char str2[] = "hello world";
if (str1 == str2) {
  std::cout << "char[] is same" << std::endl;
}
else {
  std::cout << "char[] is NOT  same" << std::endl;
}
char *pstr1 = "hello world";
char *pstr2 = "hello world";
if (pstr1 == pstr2) {
  std::cout << "char* is same" << std::endl;
}
else {
  std::cout << "char* is NOT  same" << std::endl;
}
```
以数组形式分配的两者指针不一样，以指针方式分配的指向同一片内存(常量字符串)
理由？

1. 在stack上分配空间。因为定义的是一个字符数组，所以就相当于定义了一些空间来存放"abc"，而又因为字符数组就是把字符一个一个地存放的，所以编译器把这个语句解析为
2. 这是一个指针,size=4/8, char *p = "abc" 不允许了，应该用const char *p="abc"，这个还是常量

## 容器复杂度
|Container|Insertion|Access|Erase|find|persistent iterators|
|---------|-------|------|-----------|-----------|----------|
|vector/string|Back:O(1) or O(N),amortized:O(1)|O(1)|Back:O(1),    Other:O(N)|Sorted:O(LogN),                                       Other:O(N)|No
|deque|Back/Front:O(1) Other:O(N)|O(1)|Back/Front:O(1) Other:O(N)|Sorted:O(LogN) Other:O(N)| reference only
|list/forward_list|Back/Front:O(1) with iterator:O(1) Index:O(N)|Back/Front:O(1) with iterator:O(1) Index:O(N)|Back/Front:O(1) with iterator:O(1) Index:O(N)|O(N)| yes
|set/map|O(LogN)|-|O(LogN)|O(LogN)| yes
|unordered_set/unordered_map|O(1) or O(N)|O(1) or O(N)|O(1) or O(N)|-| reference only?
|priority_queue|O(LogN)|O(1)|O(LogN)|-| -

关于vector

All iterators and references before the point of insertion are unaffected, unless the new container size is greater than the previous capacity (in which case all iterators and references are invalidated).

Reason: A vector is a contiguous array, so an insertion causes a block shift which moves all elements after the point of insertion. If the capacity is increased, the whole block is reallocated, potentially changing its address, and so the addresses of all elements.
假如size，没有变化，不会影响，否则整个memory block 移动了

关于deque

All iterators and references are invalidated, unless the inserted member is at an end (front or back) of the deque (in which case all iterators are invalidated, but references to elements are unaffected).

Reason: A deque is an array of fixed-size arrays (see Deque in C). Addition to the either end (i.e., to the free space in one of the arrays on an end), cannot cause elements to move, so references remain valid. However, as iterators are based on counting, they are all invalidated by addition.
deque是一个把多个block串在一起的结构，不能保证内存连续，可以随机访问是因为它重载了指针操作,实现更复杂，只适合特殊场合。iterator非持久(虽然名义上要看操作)，但是reference可以(因为不会移动?元素被删掉了肯定reference就无效了)

上面还提到iterator基于counting，所以addition会导致无效，这个不太理解
An insert in the middle of the deque invalidates all the iterators and references to elements of the deque. An insert at either end of the deque invalidates all the iterators to the deque, but has no effect on the validity of references to elements of the deque.
看上去是由于增加了iterator后，每个block有多少iterator需要重新计算

set/map应该也没影响，增加或者删除其它iterator，和list类似，但是hashmap会影响，因为bucket变了

Insert N items
http://stackoverflow.com/questions/15514893/complexity-of-inserting-n-items-to-an-empty-stdmap
O(log1+log2+..+logN)=O(log(N!))~O(NlogN)


Vector 的插入复杂度平均是O(1)
见:
http://cs.stackexchange.com/questions/9380/why-is-push-back-in-c-vectors-constant-amortized
增长因子~1.5

## 排序的复杂度

|Heapsort|Quicksort |Insertsort  |Mergesort  |  BinaryTreesort |selectionsort|
|-----------|-----------|-----------|-----------|-----------|---------------|
|N*LogN|N*LogN            |N^2            |N*LogN|N*LogN|N^2
|不稳定|不稳定            |稳定            |稳定||




假定在待排序的记录序列中，存在多个具有相同的关键字的记录，若经过排序，这些记录的相对次序保持不变，即在原序列中，ri=rj，且ri在rj之前，而在排序后的序列中，ri仍在rj之前，则称这种排序算法是稳定的；否则称为不稳定的。



# STL 实现相关
## 实现vector
参考company/squarepoint_vector.cpp

## thread safe queue
参考实现mscpp/others/safequeue.cpp
```
using Resource = safequeue::Resource;
using BlockingQueue = safequeue::Queue<Resource>;
BlockingQueue que;
cout <<"push ===============\n";
{
  Resource res;   //ctor
  que.push(res);  // copy-ctor
} // res dtor

 
pop 
T pop() {
    unique_lock<mutex> lk(mux_);
    cond_.wait(lk,[this](){return !queue_.empty();});
    T front(std::move(queue_.front()));  //copy ctor (NRO)
    queue_.pop_front();  // dtor
    return front;
} 


cout <<"pop ===============\n";
{
    Resource r2 = que.pop();
} // r2 dtor
```

使用了shared_ptr后
```
push ===============
res ctor
copy-ctor
res dtor
pop ===============
copy-ctor
res dtor
res dtor
push shared===============
res ctor
copy-ctor
res dtor
pop shared===============
res dtor  少了copy-ctor
```
## string
### 几种实现
参考muduo一书
COW, 短字符串, eager

### 写一个String (chenshuo)
http://coolshell.cn/articles/10478.html
测试代码
```
void foo(String x)
{
}
 
void bar(const String& x)
{
}
 
String baz()
{
  String ret("world");
  return ret;
}
 
int main()
{
  String s0;
  String s1("hello");
  String s2(s0);
  String s3 = s1;
  s2 = s1;
 
  foo(s1);
  bar(s1);
  foo("temporary");
  bar("temporary");
  String s4 = baz();
 
  std::vector<String> svec;
  svec.push_back(s0);
  svec.push_back(s1);
  svec.push_back(baz());
  svec.push_back("good job");
}
```

能够被以上程序成功执行.
一开始写的熊样:
```
#include <string.h>
#include <stdlib.h>
#include <vector>
namespace it
{

class String {
  public:
    // ctor
    String():m_data(nullptr) {

    }
    // ctor
    String(char *ap) {      
      m_data = static_cast<char*>(malloc(strlen(ap)));      
      strcpy(m_data, ap);
    }

    // copy ctor
    String(const String&rhs) {
      if (rhs.m_data != nullptr) {
        m_data = static_cast<char*>(malloc(strlen(rhs.m_data))); // access private member?
        strcpy(m_data, rhs.m_data);
      }
    }
    // dtor
    ~String() {
      if (m_data != nullptr)
        delete m_data;
    }

    // copy assignment
    String& operator =(String &rhs) {
      if (m_data != rhs.m_data) { // m_data not initialized
        if (m_data != nullptr)
          delete m_data;
        m_data = static_cast<char*>(malloc(strlen(rhs.m_data))); // access private member?
        strcpy(m_data, rhs.m_data);
      }       
      return *this;
    }

private:
  char *m_data;
};
}
```
Example:
为了面试时写代码不出错，本文设计的 String 只有一个 char* data_成员。而且规定 invariant 如下：一个 valid 的 string 对象的 data_ 保证不为 NULL，data_ 以 '\0' 结尾，以方便配合 C 语言的 str*() 系列函数。
```
#include <utility>
#include <string.h>
 
class String
{
 public:
  String()
    : data_(new char[1])
  {
    *data_ = '\0';
  }
 
  String(const char* str)
    : data_(new char[strlen(str) + 1])
  {
    strcpy(data_, str);
  }
 
  String(const String& rhs)
    : data_(new char[rhs.size() + 1])
  {
    strcpy(data_, rhs.c_str());
  }
  /* Delegate constructor in C++11
  String(const String& rhs)
    : String(rhs.data_)
  {
  }
  */
 
  ~String()
  {
    delete[] data_;
  }
 
  /* Traditional:
  String& operator=(const String& rhs)
  {
    String tmp(rhs);
    swap(tmp);
    return *this;
  }
  */
  String& operator=(String rhs) // yes, pass-by-value
  {
    swap(rhs);
    return *this;
  }
 
  // C++ 11
  String(String&& rhs)
    : data_(rhs.data_)
  {
    rhs.data_ = nullptr;
  }
 
  String& operator=(String&& rhs)
  {
    swap(rhs);
    return *this;
  }
 
  // Accessors
 
  size_t size() const
  {
    return strlen(data_);
  }
 
  const char* c_str() const
  {
    return data_;
  }
 
  void swap(String& rhs)
  {
    std::swap(data_, rhs.data_);
  }
 
 private:
  char* data_;
};
```
如何解决:
T s0=s1;(copy ctor) s0=s1;(???) assignment
主要问题,copy assignment里同时涉及构造本对象和拷贝对方，m_data如何初始化问题，需要加入swap

http://coolshell.cn/articles/10478.html
需要有测试代码

String实现的特殊之处，使用一个char*来保存raw data，那么copy ctor等等的时候需要注意
理论上copy ctor可以接受non-const的参数，而且const版本不存在的时候会调用non-const版本，但标准是使用const版本
提供一个c_str()和size() helper函数

定义了:
String& operator =(const String &rhs)  // pass by reference
String& operator =(String rhs)  // pass by value
那么
String s2(s0)
s1=s2 //这个无法判断使用pass by value还是pass by reference

更加深入的是提供C11的构造函数
```
String(String&& rhs)
: data_(rhs.data_)
{
  rhs.data_ = nullptr;
}
```
调用场景
返回一个函数的局部变量，编译器会做优化
String baz()
{
  String ret("world");
  return ret;
}

传递一个临时变量
svec.push_back("good job");

这两种情况似乎编译器直接合并了两个ctor，从而无法调用move ctor
String getRValue()
{
  return String("rvalue");
}
String s11((String("abcd"));


除非用move语句来指明
String s11(std::move(String("abcd")));

## 写一个smartpointer(CCI)
难点
reset()
Refcount 怎么声明和管理的
Copy ctor,如何连接rhs的refcount?
Default ctor中是否创建refcount实例

==实现
实现copy control:default ctor,copy ctor,copy assignment,dtor

Refcount 声明和管理
VC: 从一个ptr_base继承，其带有一个refcount成员.
My:构造一个struct,实则上面试中可以直接使用一个原子变量，使用new创建

Default ctor:
My:设置refcount为nullptr
VC: 空的shared_ptr,refcount也为nullptr

Copy ctor
VC: 调用reset()函数，实则也是new refcount，对于
My: 直接new refcount,


Dtor
VC:检查refcount指针是否有效，有效的话调用dec(),问题是否会造成refcount野指针？不会，指针有效意味着count有效，count减为0之前不会删除指针。

```
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class SmartPointer{
public:
    SmartPointer(T* ptr){
        ref = ptr;
        ref_count = (unsigned*)malloc(sizeof(unsigned));
        *ref_count = 1;
    }
	
    SmartPointer(SmartPointer<T> &sptr){
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++*ref_count;
    }
	
    SmartPointer<T>& operator=(SmartPointer<T> &sptr){
        if (this != &sptr) {
            if (--*ref_count == 0){
                clear();
                cout<<"operator= clear"<<endl;
            }
            
            ref = sptr.ref;
            ref_count = sptr.ref_count;
            ++*ref_count;
        }
        return *this;
    }
	
    ~SmartPointer(){
        if (--*ref_count == 0){
            clear();
            cout<<"destructor clear"<<endl;
        }
    }
	
    T getValue() { return *ref; }
    
private:
    void clear(){
        delete ref;
        free(ref_count);
        ref = NULL; // 避免它成为迷途指针
        ref_count = NULL;
    }
   
protected:	
    T *ref;
    unsigned *ref_count;
};

int main(){
    int *ip1 = new int();
    *ip1 = 11111;
    int *ip2 = new int();
    *ip2 = 22222;
    SmartPointer<int> sp1(ip1), sp2(ip2);
    SmartPointer<int> spa = sp1;
    sp2 = spa;
    return 0;
}
```


# STL 相关
## STL的线程安全问题
Effiective STL 12
1、多个线程读是安全的。多个线程可以同时读同一个容器的内容，并且保证是正确的。自然的，在读的过程中，不能对容器有任何写入操作。
2、多个线程对不同的容器做写入操作是安全的。多个线程可以同时对不同的容器做写入操作。

Shared_ptr的线程安全问题(chenshuo)
Shared_ptr引用计数是安全及无锁的，释放对象是线程安全的
但是对对象的读写则不是

迭代器失效场景(chenshuo)
一个线程读取容器，取得一个iterator,另一个线程往容器里插入了新数据(可能导致容器重新分配内存)

**Vector push_back的平均复杂度**
jumptrading
简单分析如下：
    考虑vector每次内存扩充两倍的情况。
    如果我们插入N个元素， 则会引发lgN次的内存扩充(1,2,4,8…扩充，第8个元素时扩充3次)，而每次扩充引起的元素拷贝次数为2^0,  2^1, 2^2, ..., 2^lgN.把所有的拷贝次数相加得到 2^0 + 2^1 + 2^2 + ... + 2^lgN = 2 * 2^lgN - 1 约为 2N次.共拷贝了N次最后一个元素， 所以总的操作大概为3N 
1+2+4+8+16…->2N-1    
所以， 每个push_back操作分摊3次， 是O(1) 的复杂度。

Now if we do the amortized analysis of the push_back operation (which I found here) we'll find that it runs in constant amortized time. Suppose you have n items and your multiplication factor is m. Then the number of relocations is roughly logm(n). The ith reallocation will cost proportional to mi, about the size of the current array. Thus the total time for n push back is ∑logm(n)i=1mi≈nmm−1, since it's a geometric series. Divide this by n operations and we get that each operation takes mm−1, a constant. Lastly you have to be careful about choosing your factor m. If it's too close to 1 then this constant gets too large for practical applications, but if m is too large, say 2, then you start wasting a lot of memory. The ideal growth rate varies by application, but I think some implementations use 1.5.

Constant (amortized time, reallocation may happen).

很不幸，如果 vector 采用 N*2 的内存增长模型(通常如此)，那么在最差的情况下，空间复杂度就是 2*N ，最好的情况下为 N(所有的内存都用上了)。平均来讲，空间复杂度为 1.5*N .也就是说，通常差不多有一半的内存是被浪费的。

Vector容量增长方式(jumptrading)
Multiplication factor = 1.5




## TODO 找出有序/无序数组交集(chenshuo)
set_intersection 找出交集。尝试自己实现
必须是有序数组
it = std::set_intersection(first, first + 5, second, second + 5, v.begin());
无序不重复数组
1.	逐个比较 O(N^2)
2.	排序后一次循环set_intersection O(NLogN)
3.	Hash O(N)



# network
## epoll
IO multiplexing
参考http://www.gcjlovecl.ltd/80-%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E6%88%98/05-%E7%AC%AC%E4%B8%89%E6%A8%A1%E5%9D%97%EF%BC%9A%E6%80%A7%E8%83%BD%E7%AF%87%20%2812%E8%AE%B2%29/23%E4%B8%A8Linux%E5%88%A9%E5%99%A8%EF%BC%9Aepoll%E7%9A%84%E5%89%8D%E4%B8%96%E4%BB%8A%E7%94%9F.html

- epoll_create=>epollfd,定义epollin|epollET
- epoll_ctl(epoll_ctl(epollfd, EPOLL_CTL_ADD, socketfd, &event) == -1)
- epoll_wait(epollfd, events.data(), ::max_events, -1);

然后在一个while() {循环检测EPOLLIN时间和其他ERROR事件}
EPOLLOUT大部分时间都是可以写的，因此只有在写失败EAGAIN的时候才需要设置。

初步感想,该epoll实现非常底层，需要使用一些高级的实现

# HFT
首先分清交易频率，高频还是中低频，高频的多数是做市商，没有很复杂的策略，但是对速度要求高，要分解每个tick
一般网络延迟在1-1000ms
业务处理控制在10-100us(0.1ms),

因此，需要从几个方面:
1. co-loc，以及FPGA，专有网卡Solarflare,Mellanox，openonload(替换协议栈),这个不谈了
2. 网卡, 使用dpdk bypass kernel,弃用网卡中断，直接poll网卡，数据传递到user space.
3. 需要选择一个好的IO模式，例如boost的async io
4. 使用大页内存，cpu亲和性,numa，无锁队列,内存池技术


C++/服务器调优, 
1. disable hyperthreading，2. turn on over clocking, 3. disable Nagle's algorithm(NO_DELAY)，4. set cpu affinity and isolation(CPU亲和性,NUMA)
2. 避免使用堆,避免异常处理，检查
3. 使用CRTP，模板，避免虚指针，继承,使用POD,使用array，而不是vector，不用STL(感觉极端了,变成C style了)
4. 使用valgrind/profile工具对hotpath进行优化
5. 内存使用pool,cache friendly(false sharing)，连续内存，使内存对齐(tbb)
6. 使用共享内存/大页内存来保存实时信息，下面挂一堆consumer,再由consumer把数据转存到持久的数据库,这个过程涉及到一写多读的线程安全性（TODO）参考openhft/chronicle-queue内存数据库


队列的使用
SPMC=> single producer multiple consumer
1. 无锁队列,SPMC,SPSC,MPMC (p-producer, c-consumer)
2. 可以将MP转化为多个SP，原因是MP的实现一般较重，例如用了CAS,mutex
3. SPMC的话除了读写锁还有什么? atomic操作估计不行，因为有多个Consumer /TBD
4. 是否强制全系统无锁

Debug
靠replay,debug加log

其它
系统的扩展性和高速是一对矛盾，没法兼顾,直接一个单线程收数据兼处理，不写log可能最快
使用multicast来接收数据，可能也有
要是象恒生那种API，不见得能有多高频
吞吐量和延时是矛盾的，吞吐量超过一定限度latency会增加
disruptor LMX是一个消息系统?

策略
基于orderbook的策略?
market maker的策略不是很懂，主要是保持流动性，但不明白如果盈利，可能靠rebate?
中低频，就是传统的indicator？
另外还有量化的，例如相关性,择时之类？多因子
deep learning

HFT预期延时一般在几十ms,如果有FPGA应该更低
md(market data)-->写入内存数据库journal-->策略插件读取
td(trade data)-->可以和行情进行合并，形成一个虚拟journal，合并考虑最新行情和上一次的回报以决定下一次下单

策略引擎咏春的代码中，大家可以看到行情处理（MD - Market Data）、策略计算（BL - Business Logic）、柜台交互（TD - Trade）是分别独立的模块，每个模块都运行在自己独立的进程空间中。

问题
最新行情应该形成一个order match?
1写多读的情况
order match的设计目前比较土，使用treemap来做

https://brahman.sg/
使用bloomberg API，目前主要是FX option数据,后面会有其它asset,stock,bond 2Mbps
需要maintenance work,IT infrastructure
GUI or websocket 来反映实时数据
GIL
decorator
args,kwargs
apply function
numpy array difference list
numpy boolean type with python
quickest way to do column multiply
zdict 转换list to dictionary
streaming 的理解




# linux 性能优化
参考linux 性能优化， 工具
top,htop,平均负载, uptime, ps,
pidstat，常看进程cpu具体信息(sysstat包里)
mpstat (disk，看到iowait), iostat
vmstat 分析系统的上下文切换和内存, in中断次数,cs上下文切换次数, r就绪队列 b 不可中断睡眠状态进程数
dstat =vmstat,iostat,ifstat, 僵尸进程
strace， 系统调用
stress 模拟负载
sysbench 模拟多线程调度瓶颈
netstat 可以看到网络的队列
sar 网络
/proc/cpuinfo
/proc/interrupts
/proc/stat各项统计 
/proc/softirqs 软中断
systemtap
linux-perf cpu采样,花费最多时间
execsnoop 针对短寿命的进程
ptree 进程树

内存中的buffer(raw disk)/cache(fileio)
cachestat/cachetop (bcc)查看缓存的情况
pcstat 指定文件在缓存中大小
dd 用于测试对文件的读写 O_DIRECT绕过系统缓存
memleak（bcc） 可以跟踪系统或指定进程的内存分配，释放请求
swap => kswapd0 内核线程来定期回收内存, numa结构，每个都有自己的内存
pmap 进程内存空间工具

c23
## 最重要的几个工具
top,vmstat,pidstat

## java调试
GDB + 配置

page211


# 术语
Square bracket 方括号
Parenthesis 圆括号
测试

# CPP
CPP11 
实现operator==()，需要考虑异常安全性,使用一个临时变量来swap ,临时变量可以随后释放空间

参考实现一个字符串,
一个空字符串至少长度为1,内容为\0,否则很多函数上实现不方便。具体参看
CCI
Std中如果传入一个nullptr作为字符串，会抛出异常。


Swap
(barclays2015-06-22)
为什么copy assignment里面喜欢用swap来交换
->因为operator=里面涉及了新资源的申请，重新分配赋值，如果有异常，会导致dangle指针。Operator并不涉及对象构造，所以对象的状态无法保证(即使用try-catch 捕捉的话，异常导致的状态仍然存在)
可以使用try-catch来精心安排代码避免异常状态，不过更好的办法是使用copy and swap 技术
有两种情况,一个是接受value，一个接受reference(需要一个额外的local variable temp)

 

使用copy and swap基于这样一个原则:
在副本上修改，然后和原件进行交换(因此要保证交换这个动作的异常安全性)，不要直接在原件上修改。这个过程可以大幅降低异常的可能性。

普通版本的swap
template<typename T>
void swap(T& a, T&b) {
	T tmp(a);
	a = b;
	b = tmp;
}

效率太差，为了处理那些pimpl实现(handle-body),需要一个public swap成员函数，外加一个特化版本(specialization)
namespace std {
	template<>
	void swap(std::string&a, std::string &b) {
		a.swap(b);
	}
}






## 综合
network io: GRPC, boost asio
Log - google/glog, boost.log

**cpprest sdk microsoft**
cpprestsdk is in maintenance mode and we do not recommend its use in new projects. We will continue to fix critical bugs and address security issues.

