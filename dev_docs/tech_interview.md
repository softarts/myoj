# SOFTSKILL
## HR culture interview

**Self introduction / tell me about youself**

My name is jon.I have been working in large-scale high performance low latency system development since 2010. My background includes system programming, sw development, performance tuning, coredump and debug analysis. My core strength is c++, I am holding java developer certification.in my spare time, also heavily use python to develop some tool to do some equity fundamental data analysis.

I am a sw engineer,  started my career at alcatel-lucent china 14 years ago. Have been engaged in many large-scale complicated telecom system development during my tenuant in alcatel, nokia and agilent/jdsu. These system are widely deploy at telecom operator network such as singtel, Verizon, china mobile.
My major is telecommunication, my core strength is c++, I am holding java developer certification as well.
I came to singapore 5 years ago. Living here with my family.

**How do you know the company(spire)**

Spire was founded in 2012 as Nanosatisfi, Inc. growth rapidly company, office in Glasgow , San Francisco and Singapore
Launched the first satellite arduset on 2013 Aug. create ArduSat, a crowd-funded satellite, which was launched on August 3rd, 2013

Produce low cost, low earth orbit cubeset standard satellite.used for tracking ships, measure weather data(temperature,pressure, precipitation沉淀物). Trade monitoring, search and rescue, piracy
Data type is AIS
2014 announced series A round funding.

## Give me one weakness you have
Financial company:
Probably the weekness is I don’t have financial background. I am lack of financial area experience.

Others:
Sometimes I feel a bit difficult to balance the complication and efficiency. 
A solution is simple but not efficiency,
B solution is complicated but efficiency.

As a developer I want to get thing done perfect thus choose B
As a technical lead the first thing is get thing done right I will consider A firstly, then improve it at the second round, but making trade-off is not easy.

都不是什么好的回答


**Strength, if I were to call your Boss, how would they describe you**
Committent
Lead a team, work overtime and on weekend, build up a component from scratch, to solve a very complicated performance issue in the project.

**Self-motivated**
Self-taught a new knowledge/programming language which is need for a new project,  and get a developer certification as well

**time management.**
handle multiple tasks, dividing overwhelming task into smaller feasible ones

**where do you see yourself in next 5 years**
I want to absorb much of the industry knowledge and also to sharpen my technical knowledge. In next five years I see myself playing various roles in a team from a developer to leading a team.

If a say I would like to be in a position where I can handle more responsibilities and I can cope with new challenges and work with the innovative people so that I can learn from them.

**biggest achievement**
I came to Singapore on 2009, as a new immigrant and a new comer to the team, I quickly build my reputation by good quality work and short turnaround time among the local and global team. My manager are confident my ability and hand over more and more critical task to me. My last year performance review, my manager has same comment.

**What motivates you?**
I am motivated by solving engineering problem/challenge within deadlines.  as it gives me a sense of accomplishment,
I am also motivated by building up a large system which people daily life can depend on it.like what I have done in alcatel, nokia and agilent/JDSU

**What do you like and dislike about your job**
I enjoyed the team I worked with. They are friendly and smart people. I actually enjoyed going into work each morning. It is fun to solve those engineering problem together with the team.

The people I worked with at JDSU were top notch at what they do. Through my experience there, I learned a lot about business/engineering knowledge, and strategies for leading a team in a large group project setting. I feel that as valuable as that experience has been, I am anxious to work on more specialized projects where I will have the opportunity to be more of a leader.

**Dislike**
Basically the job is good, but unfortunately the company is in intensive competition and downtrend market.the BU lost a lot of chances during past years and have reorgnazation for couple of times.

In this situation , opportunities for me there were limited

**Difficulty/challenge during development**
Situation – 
The most recent challenge is as a developer, face the customer complaint and huge pressure. When I was in JDSU, I was tasked to solve customer system crash issue. Issue has been escalated to CEO, we have risk of lost customer.

Task – 
The system crash very frequently and unpredictable, fix it without interrupting the system operation.

Action – 
Coordinated the team and brainstorm, analysis the problem and get plan A.
(a)	Create a simulated environment in SG lab to do the test 
(b)	Monitor customer system log 24 hours.
(c)	Operation window is very short, to reduce time cost. I test serval fix packages at the sametime to isolate the suspected part
I Also create backup plan(work around) in case unable to find the root cause.

Result - 
Finally I managed to get the schedule back on track. I am able to successfully troubleshoot the issues and solve the problems, within a very short period of time.

One custormer site Not allowed copy in and out library(and data), have to debug without symbol, read asm code, check cpu register. Isolate suspect code.work overnight.very difficult time.

另一个difficuly, 和US cooperation
I think it is communication with US, remote communication. we could not communicate during the asian day time, but instead wait till night or next day for a reply. 

That I cope with communication skills, 
1. write time bullet points before meeting, to make counterparty easier to understand my points. 
2. cover the most important thing I want to convey/ persuade first. 
3. do get prepared, prepared with supporting evidence, testing results, example etc. 
also one thing it to win the confidence from US. that is by showing our high quality deliverables.

Describe a situation where others you worked on a project disagreed with your ideas, and what did you do? 

I would talk with the person to understand the reasons behind, whoever has the sound backing would win the other. I think I am lucky that the people I met are smart people and easy going people, I treat work as work, very professional, usually I do not have hard time on this. 



### Spire culture interview
Introduce yourself
How do you know the company (JD)
Strength,weakness(focus detail)
How do you see yourself in next 5 years
Ask:
Looks spire is very small company, how many people ? 60, Singapore 7
Why Singapore, not shanghai,HK, related to customer, or easier to recruit people
Company culture?engineering oriented or sales oriented?
Cubeset satellite compare with the others produced 5 years ago
About CEO?engineering background?

How would your friends describe you?

Love child, love to pay LEGO with my child,
Geek, try to hack and fix every electronic equipment.

**Tell me about a difficult decision you made in the last year?**
Don’t have any difficult decision made last year.
The last difficult decision is 5 years ago.

Ask interviewer
What are some of the key projects currently being worked on?
Brief introduction of current project
What’s this role developing in the next 2 years?

### ATPITUDE TEST EXAMPLE
1）  1,     1,     2,     3,     5,     ?

https://www.indiabix.com/aptitude/problems-on-hcf-and-lcm/


# 基础题总结
##	LINUX SYSTEM PROGRAMMING
IO
IO multiplexed
VFS linux 虚拟文件系统，定义了一套API, 具体的文件系统都要支持这套API, read,write等系统调用经过VFS后路由到正确位置。
Page cache -  /proc/sys/vm/swappiness 
Page writeback - 延迟写操作， pdflush ,page dirty to disk

Stdio
fopen,fclose,...fgetc,fputs,fgets,fread,fputc
线程安全 - read/write yes, fread 根据3.11节，也是线程安全的, 但是如果想避免交织interleaving 读写，就要使用flockfile,另外也提供了不加锁的io api, e.g. Fputc_unlocked
提高性能-使用scatter-gather IO, writev

Adv IO
readv & writev
Epoll  -select 缺点，fdset 1024, and too slow to iterate in for loop, edge-trigger必须数据准备好,level-trigger，数据开始写/读
Mapping-io (mmap) no buffer copy,memory waste mremap, 微调性能posix_fadvise,随机读，预读
Aio 异步io, seek 是最慢的操作之一，需要移动磁头
io-scheduler：read-fifo/write-fifo has expire time; CFQ complete fair queuing,
配置 io scheduler echo cfq >/sys/block/hda/queue/scheduler
User-space scheduler sort by inode-id

进程管理
Pid_t, fork -> create new process, copy on write->change->page out interrupt->copy page(done by MMU)
exec(system call)execl,execlp,execv...
Vfork ->not useful
Exit, SIGTERM,SIGKILL, atexit->dtor static variable/some functions
wait(for process exit),waitpid
Setuid,setgid
Daemon()..

高级进程管理
Scheduler: Preemptive, NUMA,SMP, 
O(1) scheduler -> 选择下一个运行进程的复杂度是O(1)	,按时间片和优先级来划分
内核没有线程概念，都是进程。
优先级-20~19, nice越高优先级越低,setpriority/getprioriy, 
sched getaffinity() 和 sched setaffinity() 处理器亲缘性
调度策略:sched_fifo(只要具有最高优先级就一直运行), sched_rr(时间片) > sched_other
Rlimit 设置core大小，可以创建的文件大小，可以使用的CPU长度

文件与目录
每个文件对应一个inode
Fstat,chmod,fchmod,chown,getcwd,mkdir,rmdir
Hardlink ->same file,
Symbol link 不同的文件系统上

## 线程安全
线程安全有不止一种定义，而且互不兼容。根据《Java Concurrency in Practice》的定义，一个线程安全的 class 应当满足以下三个条件：• 多个线程同时访问时，其表现出正确的行为。• 无论操作系统如何调度这些线程， 无论这些线程的执行顺序如何交织（interleaving）。• 调用端代码无须额外的同步或其他协调动作。依据这个定义，C++ 标准库里的大多数 class 都不是线程安全的，包括 std::string、std::vector、std::map、std::shared_ptr 等等。而 C 系统库大多数函数是线程安全的，包括 malloc/free/printf/gettimeofday 等等。gethostbyname 通常不是线程安全，但 FreeBSD 的实现用了 thread local storage，因此是安全的。至于 read/write 同一个 fd 是不是线程安全，按 POSIX 定义是，按程序语义则不一定（因为有可能出现 short read/short write）；从实现看，Linux 3.14 之前的 write 不是线程安全，多线程写有 overlap 的可能，3.14 之后才是安全的。另外一种定义，同一类型的多个对象能分别被各自所属的不同线程并发访问，就算是线程安全的。在这个定义下，C++ 标准库容器和基本类型都是“线程安全的”。为了与前一种定义区别，这个一般叫做 thread compatible。

Mutex 的实现
Semaphore 实现mutex？

Pthread_mutex 实现
https://stackoverflow.com/questions/5095781/how-pthread-mutex-lock-is-implemented
首先用户面使用futex(Short for Fast Userspace Mutex),使用原子操作测试是否被占用。不占用直接锁定并返回，被占用的话使用系统调用进入内核，并使调用进程睡眠直到mutex释放。

It is both complicated and differs from Unix to Unix variant.
In Linux, for example, a system called Futex (Short for Fast Userspace Mutex) is used.
In this system an atomic increment and test operation is performed on the mutex variable in user space.
If the result of the operation indicates that there was no contention on the lock, the call to pthread_mutex_lock returns without ever context switching into the kernel, so the operation of taking a mutex can be very fast.
Only if contention was detected does a system call (called futex) and context switch into the kernel occurs that puts the calling process to sleep until the mutex is released.
There are many many more details, especially for reliable and/or priority inhertience mutexes, but this is the essence of it.
For more details see: http://linux.die.net/man/2/futex and http://en.wikipedia.org/wiki/Futex

源码:
http://sourceware.org/git/?p=glibc.git;a=blob_plain;f=nptl/pthread_mutex_lock.c;hb=HEAD
首先尝试cas 原子操作
```
oldval = mutex->__data.__lock;
      /* This is set to FUTEX_WAITERS iff we might have shared the
	 FUTEX_WAITERS flag with other threads, and therefore need to keep it
	 set to avoid lost wake-ups.  We have the same requirement in the
	 simple mutex algorithm.
	 We start with value zero for a normal mutex, and FUTEX_WAITERS if we
	 are building the special case mutexes for use from within condition
	 variables.  */
      unsigned int assume_other_futex_waiters = LLL_ROBUST_MUTEX_LOCK_MODIFIER;
      while (1)
	{
	  /* Try to acquire the lock through a CAS from 0 (not acquired) to
	     our TID | assume_other_futex_waiters.  */
	  if (__glibc_likely (oldval == 0))
	    {
	      oldval
	        = atomic_compare_and_exchange_val_acq (&mutex->__data.__lock,
	            id | assume_other_futex_waiters, 0);
	      if (__glibc_likely (oldval == 0))
		break;
	    }
```
无法锁定的话,使用futex system call

http://blog.csdn.net/jianchaolv/article/details/7544316

Futex系统调用
Futex是一种用户态和内核态混合机制，所以需要两个部分合作完成，linux上提供了sys_futex系统调用，对进程竞争情况下的同步处理提供支持。其原型和系统调用号为
```
    #include <linux/futex.h>
    #include <sys/time.h>
    int futex (int *uaddr, int op, int val, const struct timespec *timeout,int *uaddr2, int val3);
    #define __NR_futex              240
```        
虽然参数有点长，其实常用的就是前面三个，后面的timeout大家都能理解，其他的也常被ignore。uaddr就是用户态下共享内存的地址，里面存放的是一个对齐的整型计数器。op存放着操作类型。定义的有5中，这里我简单的介绍一下两种，剩下的感兴趣的自己去man futex。FUTEX_WAIT: 原子性的检查uaddr中计数器的值是否为val,如果是则让进程休眠，直到FUTEX_WAKE或者超时(time-out)。也就是把进程挂到uaddr相对应的等待队���上去。FUTEX_WAKE: 最多唤醒val个等待在uaddr���进程。

总结：
简单讲就是先尝试cas，再使用system call 



##	SCB-ZHANGYU


内核同步机制
http://www.cnblogs.com/aaronLinux/p/5904479.html
对于不可抢占单核的系统来说，如果一块临界区代码正访问一半，出现时间片轮转，时间片再次转回来，是否存在临界资源访问问题？

同步机制:中断处理，内核态抢占(访问临界资源时)，多处理器并发
手段: 禁用中断，自旋锁，自旋锁禁用中断，顺序自旋锁seqlock(避免写进程饥饿)

使用信号量来实现mutex,P(+1)/V(-1)操作
RCU概念：RCU全称是Read-Copy-Update(读/写-复制-更新),是linux内核中提供的一种免锁的同步机制。

用户态 Semaphore 如何实现?基于futex
内核态semaphore,只有允许睡眠的函数才能获取内核信号量，因为其可能睡眠，简单过程：设置当前进程不可中断，获得自旋锁，关中断，进入循环，检测计数，拿到的话break循环unlock spin,拿不到unlock spin，将当前进程加入等待队列，进入睡眠

Mutex 强调所有权，semaphore强调通知

系统调用
调用号通过eax寄存器传入。Ebx,ecx,edx,esi,edi,
Copy_from_user, copy_to_user
内核在执行系统调用的时候处于进程上下文。current指针指向当前任务，即引发系统调用的那个进程
在进程上下文中，内核可以休眠并且可以被抢占。这两点都很重要。首先，能够休眠说明系统调用可以使用内核提供的绝大部分功能。休眠的能力会给内核编程带来极大便利。在进程上下文中能够被抢占，其实表明，像用户空间内的进程一样，当前的进程同样可以被其他进程抢占。因为新的进程可以使用相同的系统调用，所以必须小心，保证该系统调用是可重人的。当然，这也是在对称多处理中必须同样关心的问题。

当系统调用返回的时候，控制权仍然在system_call()中，它最终会负责切换到用户空间并让用户进程继续执行下去。

dll 和unix so 加载
通用参数 -fPIC -shared -o libtest.so
-fPIC：表示编译为位置独立的代码，不用此选项的话编译后的代码是位置相关的所以动态载入时是通过代码拷贝的方式来满足不同进程的需要，而不能达到真正代码段共享的目的。产生与位置无关的代码并能被加载到任何地址：
使用gcc的-shared和-soname选项；
使用gcc的-Wl选项把参数传递给连接器ld；
使用gcc的-l选项显示的连接C库，以保证可以得到所需的启动（startup）代码，从而避免程序在使用不同的，可能不兼容版本的C库的系统上不能启动执行。
gcc –g –shared –Wl,-soname,liberr.so –o liberr.so.1.0.0 liberr.o –lc

使用dlopen加载，dlsym查找symbol,dlclose
nm查看符号表
strip 去掉debug符号

## TCP/IP
头部

## 图解http协议书
Apple, mihoyo, http相关
http 协议
状态码,2xx,3xx,4xx,5xx,

协议
通用格式: http报文首部--空行(CR+LF)--报文主体

**Request**
请求行,请求首部字段，通用首部字段，实体首部字段
e.g
```
GET / HTTP/1.1
Host: hackr.jp
xxxx
```

**Response**
状态行,响应首部字段，通用首部字段，实体首部字段，CR+LF(空行),报文主体
```
HTTP/1.1 304 Not Modified
Date: Thu, 07 Jun 2012 07:21:36 GMT
Server: Apache
Etag: "45bae1-16a-xxxx"
```

**header**
分为四种:
- 通用(cache-control,connection,via, date)
- 请求header字段(accept, accept-charset,authorization)
- 响应header字段(accept-ranges,age,ETag,Location,proxy-Authenticate)
- 实体header字段(Allow, Content-Encoding,Content-Length,Content-Location)
- 非HTTP/1.1首部字段(Cookie,Set-Cookie)

### http 认证方式
- basic,一般浏览器无法实现注销操作
- digest,使用chalenge/response
- ssl 客户端认证,使用证书，客户端必须安装证书
- formbase认证
- windows 统一认证(keberos认证,NTLM)

### https和证书
http协议本身是没有状态，他不能够验证通信方
防止窃听和验证通信双方，防止中间人,
http+加密+认证+完整性保护=https
使用非对称性加密，发送密文一方使用对方的公钥来加密，而解密只能使用对方的私钥

实际处理中，混合两种方法
1.使用非对称加密方式，传递后面要使用的对称加密秘钥
2.使用交换来的对称加密秘钥来通信

然而如何证明收到的公开秘钥就是网站发行的公开秘钥？
- 网站向数字证书认证机构提出申请
- 由数字证书认证机构对申请的网站公钥进行数字签名(使用私钥，SHA?)，把公钥和数字证书绑定在一起
- 服务器会把这份证书发给客户端
- 客户端可以使用数字认证机构的公钥对此网站证书进行认证,
- 确认证书有效后得到网站公钥，然后使用网站公钥对报文进行加密
- 将数字认证机构的公钥内嵌在浏览器中做到安全移交
- 有些浏览器还会内嵌中级机构的公钥

### others 
客户端证书
自签名证书
中级认证机构的证书可能会变成自认证证书
详细步骤p177


## GRPC (TODO)


#	Old interview
## SART 2011/07

CString 转为char *
F1(){return local variable}  ; F2() {return static variable}; F3(){return malloc;}
Afx_manage_state()用途
IPC的方法
Thread synchronization crition section
Debugging mode vs release mode
Container MFC/ATL/STL
Heap,stack
Singleton 的实现

## R&S 2010/09
做题，大概2-2.5小时,C三道简单的题目
1.Foo(int&,int)，检查是否明白参数的引用
2.考察const char * 和char * const的区别，给一段程序，判断错在哪里
3.程序题:partA, 如何做sort (特别指出在于0排在最后)，partB,如何将重复的数值换为1 i.e:1,3,4,1,4

C++
1.一段函数，处理char buf[]=”introduction – function”，当遇到其中的”-“时，将其替换为空格，问输出结果。
2.一个关于shallow copy的程序，会造成两个instance指向同一个memory
3.针对一个测试程序写一个类,intarray,函数包括ctor,copy ctor,data,length,setdata,和string类似，注意operator=也许需要返回引用,string& operator=(const string){}
4.描述overload和overriding的区别
5.什么叫abstract class和pure virtual func
6.为什么base的dtor需要是virtual?
7.对multi-threading的认识，常见的同步方法
8.max 宏和max函数的运行结果,如max(a++,b++)，打印出a,b

Interview:
是否用Scrum,UML

## RTS 2010/06
2010/04/14/今天见了CEO，有时候话说得太多了，需要思考一下，挑些重点的说，说多了就不知道自己说什么了

## EMC面试/2008/08/12
1.
举一个驱动的例子，如何从用户面读取内核面的寄存器,mmap?
Int a[6],a[-1]=0有何副作用 就是取前一element
有无scsi或其他总线的经验(只有开发过低速的总线)
ASM经验(主要是看代码，基本硬件已比较成熟,没有采用ASM来写驱动)
设备上用什么CPU(boardcom?)
如果setup一个完全不同的环境，你和别人比有什么优势
2.
如何发现内存泄露
如何调试low-level的driver(printk,simulator)
一个a.so的funca()中 malloc内存，在main中调用funca后再free内存有何副作用
如何调试windbg的service(由svchost运行的) windows上的都是thread?
A 和 B两台机器都要读取disk,如何同步,方案
3
如何支持MMU，OSE有无kernel/user mode
解释ACE-TAO,CORBA的开发(是一个通信infrastructure)
VLAN有无QOS,802.Q
开发什么东西(fcs,kpi,ps config)
UML中Aggregation和composite的区别
State ,abstract factory模式，好处
Clearcase 的VOB和view
解释OSE上作的low-level dsc-bus(杭州没有HW的开发，主要是application)
4.
Experience on different Company,Agilent,nokia,..
总结
1.设备驱动开发的经历(以什么作为切入点?)
2.加强OS的经验(太过庞大)

## MorganStanley 2009/02 MSDE面试

1st
http://www.possibility.com/wiki/index.php?title=CppInterviewQuestions
保存在interview 目录下面

2nd
```
1. Recent work
2. exception in ctor(可以); throw exception in dtor (not recommend,有可能无法正常释放内存)
3. why use virtual dtor? 有virtual ctor吗？(More Effective C++中见过，不过其实是每个类提供了一个clone的方法，在这个方法new 自身)
4. class baseA; class B:public baseA { B(){throw exception;} } 如何处理这种情况，假如baseA中执行了动态分配内存
A->这种情况下sub object  baseA已经构造成功
5. Sting s;auto_ptr<string> ptr = &s
A->不能使用在stack上分配的内存给auto_ptr使用
6. hash_map中的hash_key如何设计
	A->当时回答成map了.
7. 找出vector<A> vector<B>中的相同元素或者unique的元素
	A->使用hash_map set_intersection,set_union,set_difference
```


## TEK面试2009/04

multi-core的特点
pthread_cond_wait用的时候要注意什么
R/W读写锁
如何提高多核的性能，分离数据，分离任务(pipeline)，以及有效的保护共享资源
lock-free怎么实现
与项目有关(nokia,alcatel,agilent)
socket 的non-block如何实现
pthread_spin_lock与其它lock的比较
还有没有其他东西要自我介绍的(类似EMC,你认为与别人相比，在embedded上有什么优势)
笔试题
Binary 反序
防止类对象被copy,线程和进程的heap怎么用;class A{int a static int b;void func()};求sizeof(A);OSI分层,读写锁的用法，用信号量来描述？
算法复杂度,hash,array,unsort link list,unsort double linklist,sort linklist 的插入，删除，查找，查找下一个的O()
改错题,一些边界条件没考虑
智能指针

## 爱立信面试2009/06(got offer)
2009/05/26  phoneview
1.overload怎么做的
->name mangling+signature

2.lock-free怎么实现的
compare-and-swap的cpu指令

3.spin_lock和mutex_lock
->太easy了

4.用什么多线程的库
->pthread, intel TBB,CT

5.在这里做什么,为什么这么快跳槽
->杭州->上海跟老婆，现在被裁员

6.kernel/user space怎么区分的
->0-3G给user space;3-4G给kernel,通过系统调用切换，调用门，陷阱门，系统门。进程地址空间通过vm_insert_page之类的函数把VM_STRUCT 添加进来

7.网卡zero-copy怎么实现的
->直接把kernel态的内存给用户态共享

8.SCTP和TCP的比较,SCTP怎么样防止syn-flood,DDOS攻击
->multi-home.multi-stream,伪造MAC地址，防止被攻击不知道

9.IU-cs/iu-ps的协议栈
->ATM,MTP,AAL.SCTP,RNANP

10.对于overload 的函数，GDB怎么设置正确的断点,怎么切换thread

Gb,Gn,Gr,IuPS的协议栈
GTP v0和GTP v1的区别->TEID的分配，前者是随机，另一个不是
如何debug 一个crash的OS,如何知道程序crash在哪里？
RTOS的基本概念，与通用OS的比较
UML设计中，state chart,class-dirgram那些可以不要
应用层的可靠性如何设计,例如一个彩信发送协议，在应用层出错的时候处理即可，这有什么原则？
递归，二份查找法
source insight如何查找caller?(太弱智了)
hash_table如何优化？参考TBB中的做法
如何处理I/O？如有disk的IO,NIC的IO,如何分配，并使其高效
如何处理文档？doxygen
多核开发上的考虑，架构，需要通过测试来达到目的.
协议层次:SNDCP/LLC/BBSGP(BVCI)

## Ericsson 2007/07
面试题0817
Extern C用途(导出C风格的函数调用)
Inline的效率(避免宏的一些不良反应，原地展开)
什么时候用拷贝构造函数(1.为了触发编译器的NRV机制，2做深拷贝的时候避免成员拷贝,类中存在动态分配的内存时)
C++比C的好处
为什么有了malloc还要new
5种IPC
Int *p[5]和int (*p)[5]区别(指针的数组和指向数组的指针)

Gcc 中-I –l –L的用途
Return string(s1+s2)和string temp=s1+s2;return temp谁更有效率(前者，string的拷贝构造函数只触发了一次)
Class A中有一个virtual test(double)，派生类Class B:public A中有void test(int)，不是虚函数，参数定义不一样

## Credit Suisse (2010/06/23)
ctor()调用虚函数有什么结果，能否编译，可以 但是数据未准备好

virtual ptr table的实现->简单

semaphore, mutex,condition variable区别,　　

一个空白类，会默认生成什么函数->ctor,dtor,copy ctor,assignment

inline 解释

了解sharememory?(回答了MQ性能)

--

假如一个文件有多个"database",如何用awk 把子串的行数计算出来

thread和process的区别(cao),image?thread有自己的stack?TLS

为何用unix/linux/solaris,区别？

如何监控thread的状态（有什么实践意义）

## Agilent 面试 (2007)
@@@Aginlent 2007/05/22

射频方面:史密斯圆图*，莱斯分布*，快衰落，慢衰落，驻波及其单位*
小区定位过程，如何定位*，功控的作用*，GSM定位和GPS定位的关系
wimax和hspa的频谱效率,OFDM技术*，如何看待wimax的发展，主要定位。16e和16d规范的不同
毕业论文（无线传播原理）作的具体工作。
UTRAN测试中承担的角色，一致性测试,IOT测试的目的；需要自己写测试脚本吗？信产部测试和中移测试的不同处
nokia中的工作和asb中有何不同,在asb utran中属于哪一块？(nodeb,rnc,OAM,应该讲rnc-oam-OMCR),更熟悉windows还是unix（从大一开始，所以..）

TTCN*
alcatel的手机部门和sbell的手机有何关系，手机模块的定位(车载，物流，海关)，模块的体积大小

nokia的工作氛围比asb好*,工资低福利好&
agilent的工作主要和上游厂商合作，开发和完善测试规范。


# 2015 COMPANY INTERVIEW

##	Barclays
scope_ptr, shared_ptr, make shared, enable_shared_from this
reverse string, swap, 参考leetcode 344
SQL select count

Barclays AETT – tyoko
Technical phone screen interview@2015-09-15
Compiler会自动为class生成的函数 - ctor,copy,assignment,dtor,move ctor/assignment
何时使用virtual dtor
如果不用virtual dtor会怎样
能否在ctor中使用virtual function ->不要
能否在dtor中throw exception - no
Catch by reference/value/pointer->MEFC13
Primary key和 foreign key 分别是什么
Inner join, left outer join, right outer join 分别是什么
Ctor中没有返回值如何处理错误 exception
Ctor中抛出异常会有什么问题 -> 已经构造的对象会被call dtor,其余的可能有些资源没有回收
Ctor抛出异常的话会不会调用dtor –>已经构造的对象会被call dtor
有什么技术可以用来避免这种ctor异常造成的资源泄露, smart pointer
什么是dead lock,如何避免
RAII原理是什么，如何管理资源
Autoptr可以用在容器中吗
Dynamic_cast干什么用的, 用在reference和pointer的差别是什么 (pointer will throw excep)
如何删除一个数组 ->delete square bracket  (round bracket)
一个函数以以c style 数组作为参数，如何传递一个vector类型的变量
List 和 vector的区别, 后者连续内存,且可能会重新分配内存
如果要把一个类放到容器中，必须要实现什么operator -> less than “<”

有什么问题->问得太复杂且没有必要了，saw a JD in Singapore, project is also based on BARX platform. What is  the different,其实局外人根本没必要了解这些，也说不清楚，作为first round interview，只需要了解下对方的项目，team size.
或者换一个说法，can you tell me about BARX, I heard many project are based on this platform


##	Jump trading 2015/06
OS/C++? 从构造函数问起，如何创建Object,new(C++)/malloc(C),区别(new调用构造函数),构造函数内存不足的时候抛出什么异常(bad_alloc),
如果不想抛出异常，而是返回NULL ptr如何(operator new),然后malloc,再使用new placement调用构造函数。??->TODO 需要一个wrapper? operator new返回null的话无法继续初始化

如果抛出了异常，系统如何处理->调用member的dtor,其它的raw ptr会造成内存泄露
能否在析构函数中抛出异常，为什么?行为未定义,假如dtor是异常触发的，在dtor中在抛出异常会导致SHE找不到匹配的catch而dead loop.
用过什么STL, vector push_back 的average complexity
增长维度如何
Template,4->32bit;8->64bit,如何在编译时根据4/8来决定使用platform,
参考https://zh.wikipedia.org/wiki/%E6%A8%A1%E6%9D%BF%E8%B6%85%E7%B7%A8%E7%A8%8B
```
template<int N>
struct Factorial 
{
enum{ value = N * Factorial<N -1>::value};
};

template<>
struct Factorial<0>
{
enum{ value =1};
};

// Factorial<4>::value == 24
// Factorial<0>::value == 1
void foo()
{
int x = Factorial<4>::value;// == 24
int y = Factorial<0>::value;// == 1
}
```
参看template一章

X = 20;
const int& i = x;
auto j = i; //j的类型->int?
-> rule3 i:const int &,去掉const &，剩下int

参考EMC 第一章

**2019/5/25**
自我介绍，没准备好，以后简练点
举出一个move的例子，举了a+b+c+d，不是很恰当，后来举了构造函数和移动构造函数

TopK of N element,优先队列的数据结构有点忘记了，其实就是bin search tree和一些定义，全节点，每个子树都是最大堆，插入的时候需要rotation之类。

Virtual function的原理，virtual function跳转的cost,能否估算整个系统的cost
不太明白这题目，以后还是该多问问
内联函数-比virtual function更快
but that the indirect jump usually cannot be branch-predicted.跳转无法预测
instruction cache miss
jump to a very far address?


一个文件很多行，怎么去除重复的行?使用hash?2次遍历？
总结，很多时候要介绍原理，这个有点欠缺；其次C++03有点忘了，需要捡起来。

##	flextrade2015-06-24
DI 依赖注入,怎么实现的,C++可以怎么做,虚拟构造
Git rebase/merge区别
OO有何特点
->封装/多态
enable_shared_from_this怎么实现, has a weak_ptr
shared_ptr的应用场景

low latency如何系统调优
->参考LMAX
->另一个TBD

a++*++a,
->vc=36,gcc=35,java=35,看来前面a的结果影响到后面的a;实际上http://c-faq.com/expr/seqpoints.html提到一行最多只允许修改一次表达式。
最困难的事情/挑战，如何debug.
二维数组,旋转一个二维N*M的数组


## SCB 2015 
自我介绍,jdsu project, nokia, alcatel-lucent,
Vtune 哪些counter,->cpu_stall,cpi,ext_snoop
Queue,mutex,condition variable, atomic, cas (atomic实现应该是基于cas)
Boost哪些库 spirit->decode text.
auto_ptr有没有copy ctor->no copy ctor, can’t use in container.? Assignment will transfer ownership ->有吧
应该有copy ctor,但不是const,因为要对原有的对象执行release(),push_back(调用的是copy ctor)的过程中会转移ownership
shared_ptr, weak_ptr的用途,weak count的用途
hashmap和map的区别hashmap的复杂度,何时选用map而不是hashmap.
Map的实现,red black tree,什么叫平衡,map insert的复杂度
Vector 插入的复杂度 O(N) for insert at middle

dynamic_cast 有什么额外要求->In order for dynamic_cast to work the object needs to be polymorphic. The reason for this is that dynamic_cast needs somewhere to store the type information that is will use to perform the cast, and it does this by storing the information alongside the vtable for the class. In order for there to be a vtable you need to make at least one of your methods virtual.

virtual dtor有什么用途, base A,没有virtual dtor, A *a=new B();delete a有没有内存泄漏，B的dtor没有被调用。
特化，偏特化，完全特化->函数模板不允许偏特化 TODO

## SCB 2017
张雨c++组
One independent survey showed that 70% on people asked like coffee. Another independent survey showed that 80% of people like tea. What is the upper and lower bound of peoples who likes both coffee and tea

The best case cenario is that all 70% of the people that like tea also like coffe (the other 10% don't), so the upper bound is 70%. The worst case cenario is that from the 70% that like coffe, only 80% of them like tea, so the lower bound is 70%*80% = 56%.

// dead lock, lock not in order.

// call virtual function ->foo(int xx = default_func()) //unable compile
// cad/jpy 1%, 2% trade, expect value in some time?

// reuter book which quote disappear fast?
// move ctor is in c++11, lambda operator?

// fork 3 times,  how many times print helloworld -> 8
// pass template, double, double& parameter,  which one is faster,double?
// enable shared from this and make_shared<>()  /13

// if (!p) call new memory handler //whether run
    // 3:15 angle

    // others:
    // what kind of thread mutex would be used
    // choose between multiple process/multiple thread
    // variadle templates,perfect forward,auto f=async,what does it do when left block
    // what is weak_ptr




##	DRW 2015
Self introduction,Project,performance, how to optimization
C++11 feature:
->smart pointer, move,bind,function,
shared_ptr vs unique_ptr, when to use shared_ptr?
shared_ptr is thread safe?unique_ptr is thread safe?  ->neither
What is atomic operation -> finish in one cpu instruction 不妥
unordered_map vs stl map,complexity,

DRW 2017
Introduction-payment counter, beetalk,video streaming/python,c++
Reason - explore trading technology area
Python, Pandas vs numpy fundamental difference.
Where do you use c++, library using, ->boost in some old platform
concurrency,Golang vs c++, talk about go channel vs tbb concurrent queue
C++ stl container in multithread env, cache object in freelist. ptmalloc vs tcmalloc
Packet bypass, pfring, dpdk.
Do as fast as possible insert/delete(key)/random(), choose a container -> use a vector, 原来是一道leetcode 380
If random() return null then random again.

##	virtual Financial 2015
Codility 参考vf1~4 2015
图形和序列做得太慢了，35分钟 44/63被据

2017 - 算法题未过 


## bititan
Interview
Remove duplicated integer in a list
Find the max increasment length in an array [2,1,3,5,4]  max length = 3

US team:
About yourself
What are you doing in your project(protocol decoder, user plane process framework)
Why convert network packet into internal format
What is trick part in your project
Ask about protocol decoder
Team size.
写一个atoi, “+1234”, “-1234”，然后要求处理各种异常case: “ +1234 ” “+124sdh45”,后来直接中断去问虚函数了,考虑异常处理的时候时间长了点，实际上不要考虑那么多，直接发现错的就返回。
参考mscpp /algo/bittitan


homework 
Multithreading
Have you written multithreaded code? Please provide some context as well as the coding primitives you used
->
The most recent project I was working on is deployed on large telecom operator network(e.g. singtel, Verizon), to process network traffic in realtime. Since the network volume is quite high, the project is implemented as multithreaded application, thus it is able to process traffic in parallel.

Beside these cpu bound taskes,those IO bound taskes usually are implemented in standalone thread, Separating cpu / io task to achieve maximum cpu utilization.

The major multithreaded coding primitives I used are Intel threading building blocks(TBB) because building block provides more robustness and efficiency. Another popular library is boost/lock free queue.

I am also familiar with system level primitives (pthread, mutex, semaphore, conditiona variable, atomic operation(unix) / critical_section, interlockedexchange(windows), waitformultipleobject)

I also have experience with C++11 concurrency primitives, e.g. std::thread, promise, future, async, lock,etc


Debugging
What is the hardest problem you've had to debug? Please explain which tools / techniques you used and what you uncovered.
->
The hardest problem is random memory corruption happened 4 years ago. In the project it need to track internet flow per user. In this environment the objects are created and deleted frequently(thousands+ per second), Delete an object at A place but still have reference at B place will cause serious memory corruption and very hard to reproduce(it is triggered by a special packet thus may happen from every 5 minutes to 10 days), Call stack can’t provide much useful information(only know it is a wild pointer but don’t know where and why the pointer was deleted). Log object created and deleted doesn’t help either as in multithread and high volume data environment it will cover the root cause.

The short operation window in telecom operator, and strict operation rule(forbid coping traffic) also made the problem worse.

What I have done in this debug:

Coordinate team to review the source code thoroughly to see if any design flaw(very helpful)

Run valgrind to remove any potential memory violation and bad coding behavior. (helpful)

The standard debugging scenario is to use gdb to analysis coredump, read the source code and understand the logic behind the crash. (doesn’t help much)

To isolate the suspected part, create couple of try-fixing libraries, carefully replace them one by one. (helpful but huge effort)

In the following projects, replaced raw pointer with smart pointer. And I never see difficult memory corruption after that.


Optimization
Is there any type of code or problems you like to optimize? What is your favorite optimization technique?
->
Low throught but CPU is not hot, usually it is caused by blocking operation, such as wait for IO or other resource(lock)

CPU usage is high, run intel vtune or linux-perf to find the hotspot. 

CPU usage is high, but no hotspot. does the CPU waste time on unused stuff which doesn’t contribute to real work.

Optimize contest in multithreaded application, use finer lock, shorter lock period.minimum number of shared data.

Implement LRU memory cache to optimize IO operation

Optimize for special case, e.g. an Class is used to process length of 1..N bit data. Also have an optimization if the N<64bit.


Algorithm
Is there any interesting algorithm you've implemented for a real-world project? What does it do?
K way merge – K pipeline each has sorted data, merge them into one pipeline.


Code
public class Node
{
    public Node[] Children;
    public Node Right;
}

 
Question
Each node represents an element of a tree and specifies a list of immediate children.
The 'Children' property lists all children (in order) but the 'Right' property is set to null.
Suppose you are given the root of a fully populated tree (i.e. a Node called RootNode). Write code to set the 'Right' property so that each node is linked to its right sibling.



##	IBM 2015

5~6道选择题，简单的虚拟内存，进程/多线程
5 道编程题，感觉C++绝对写不完
1.	打印一段数字序列:1,2,3,4,5/2,4,6,8,10/3,6,9,12…
2.	给出一个数组，生成一个新数组，其中每个元素等于原数组除开对应位置的元素之外的所有元素的乘积. (product_of_array,不能用除法lc),apple
3.	一个数组，给出一个数字，找出数组中是否存在两个数的和等于这个数字 （twosum,lc）
4.	Reverse string
5.	一个链表，给出一个节点，只知道节点本身，把它删除掉，只要求画图(lc)
6.	写SQL 大意是学生表，科目表，分数表，找出其中Math最高分的学生，有mysql练习代码,TBD


第三部分是debug,有C++和JAVA，来不及做
二面推迟几次后就没有消息了


##	Greenwave
自我介绍,linux,windows多少年，boost用了哪些,c++11新特性,设计模式用了什么；router应该怎么设计，mastermind有什么改进(UI,多线程安全性,gtest,gmock),为什么这样设计,项目流程是什么,项目中的role
问了他project,OEM给verizon的，可否加入消费者的特性
拿到offer了 7700+100

##	Sixcapital
MySql有什么局限，用过oracle吗
被据

##	Spire
Hackerrank coding challenge - TBD
Phone interview
Self introduction
Prefer work 
Kernel project,
How do you see yourself in next 2 years
Programming exercise - Write FIFO queue,这里实现得不是很理想，pthread_mutex API记不清楚，node和外部资源混在一起了，平时还是要多实现，练习

What kind of work inspire you
Prefer team size
被据

##	Garena

Usually scenario = 1 hour paper test -> first round face 2 face(1 hour) | HR interview (30 min) (first day should be done here)-> second round -> VP (no technical question but talk about your career path, company culture, offer/negotiate)


Paper test 
24 questions, (multiple?) choice + 1 programming on paper(1 hour):

1.sort,algorithm
Sort algorithm(insertion sort, quick sort, merge sort, heapsort) complexity, which has worst case N^2... Which is stable sort, 
Binary tree already know inorder/preorder, figure out post-order
Put an array into minimum  heap result

2.Network
ip protocol characters(sequence number, integrity...)
What protocols are on top of UDP(choose from DNS,HTTP,....)
Tcp protocol characters (e.g. Stream, not packet boundary, high flow? Reliable? Connection oriented?)

3.OS
Some questions about page table, MMU, logical address length
IPC implementation
Encrypt algorithm, AES,MD5,CRC,RSA, asymmetric  or symmetric
Thread is cpu scheduler basic unit (correct or wrong?)

4.Database
Some question about general database knowledge, e.g. shared lock, exclusive lock, dirty read, transaction

5.C programming
Char xx[]=”hello”, “hello” stored on stack? char *p=”test” ?(a constant section?not sure)
Sizeof(xx)=6?

6.Others
I can’t remember clearly
Reliable: Component R  = 0.9, R - R -R =?
and this?
R--- R - R
     |-R - R  

Programming
Sorted Doubly linked list - can’t remember what is it, but not difficult, something like insert node in sorted doubly linked list


Face 2 face
HR: HR will ask you if you can work OT | change on project demand | work in tough time/deadline, office hour: 9:30 - 7:00 PM, don’t be too honest at this round.until you get offer.

Technical, it is quite tough, question range is wide as interviewee changed every time.

E.g.
Network programming, max connections per server port, TCP_NODELAY? Boost asio heavy used here, but better know socket API, and sync/non blocking, select/epoll..lib such as protocol buffer

Database, create index on multiple columns,  varchar 16 vs char 16?

C/C++ programming, if you say you know C++11, then general C++11 questions will be definitely asked. 

Python, also heavy used here, was asked about decorator, some other topics surely to be prepared

Algorithm, usually asked to solve a problem(e.g. Implement tail), some one was asked dynamic programming(DP), explain how to solve knapsack problem, refer to hackerrank/leet code.

Malloc how is it implemented,  fragmentation merge(buddy algorithm,etc)

Internet practice.  E.g. Bottle neck when you design a e-commerce store(search volume is huge, transaction?), how to solve it.

OS, thread/process/

24选择题
1.	证明p(1,1)为true,如何证明p(m,n) ->先证明p(1,n+1),再证明p(m,n)？
2.	Worst case = N^2的sort有 ? insertion sort/quick sort, merge sort, heapsort
3.	Stable sort 有 merge sort / （其它 binary tree sort, heap sort, quick sort）
4.	Thread是cpu scheduler 的basic unit
5.	Page table的描述， global只有一个/还是每个进程一个
6.	Const int * ptr(从右往左, pointer to const int),和 int *ptr[10](array of 10 ptr*), int (*ptr)[10] 的解释 (ptr to array of 10 int)
7.	已知二叉树的inorder和preorder输出,求postorder
8.	把某个数组建立为最小堆的最终结果
9.	Read uncommitted, 线程A在写入没有commit, 线程B这个时候读取，叫 “dirty read?”
10.	Char xx[]=”hello”, “hello”是否保存在stack上， char *p=”test”呢
11.	Sizeof(xx)的长度是不是6?(是的)
12.	Database shared lock 和exclusive lock
13.	加密算法对称的是 AES (MD5,CRC,RSA)
14.	Logicial address 大小跟什么有关 CPU length?
15.	IP 协议的描述, sequence number?integrity,
16.	TCP的特点 不是packet boundary，其它3个选项包括high flow,可靠性,面向连接等等
17.	基于UDP的协议 DNS (FTP,HTTP,TCP)
18.	属于IPC的有named pipe, shared memory, memory queue
19.	可靠性问题 r=0.9，  R –{R—R } 总的可靠性
20.	                                       |R—R} 
21.	

Sorted Doubly linked list 的插入
面试
自我介绍，项目,decoder, user plane process framework,
虚函数，static 函数(可以通过对象访问)
如何使worker thread 负荷平均分布，为何使用spsc queue, 为何使用mpmc的queue
Malloc如何实现的，(在头部保存一些信息知道尺寸，碎片合并(buddy 算法),有锁，通过brk来申请内存)
Socket  server能够有多少个连接， 例如80端口的，有新链接的时候是否新创建一个端口来与client连接
Socket nonblocking 如何发送数据包, 回答应该是epoll 可发的时候进行发送，判断已发送字节
database, 经常查询 where xxx and yyy order by,如何创建index 在两个column上, varchar 16和char 16的区别
计算bit为1的个数

2nd
介绍JDSU的项目特点
LRU+hash 的实现- sorted linked list +hashtable,因为push的永远是最新时间的数据，所以只需要把它移到链表开头
Weibo的技术难点 – 数据库/存储的设计,如何实时通知所有的follower,搜索，cache
描述浏览器-server之间的交互过程 (参考taobao10年的文章) 
Tac如何实现 较小的文件stack，较大的文件使用固定buffer

提问
百万商品/50万用户， 搜索的强度，cache

VP
自我介绍，个人特点，经验， 如何面试，比自己好的同事都是怎么样的
工作强度大，怎么看，怎么说服老板


树遍历,概率，排序，加密(算法的特性,MD5,aes)，数据库，数学归纳，操作系统，线程和进程的区别，读写锁，事务，

编程题 – 反转字符串

海量数据处理 

Tcp/ip 头部
Ddos - SYN Flood, 没有响应syn ack

Technical: How does the Internet work, Basic algorithms   , String operations Managerial: Career aspirations, projects where you learnt the most, what are you most proud of, most regretful of, how many people depart from the airport in a year etc.

1 hour of technical test (test consists of 2 parts: MCQ (24 questions of 4-choice, correct answers could be multiple), Algorithm (write a program on paper (can be written in C/C++/C#/Java)). Topics covered in MCQ: various sorting algorithms (e.g. Heap Sort, Insertion Sort, Merge Sort, Selection Sort) (mainly on the time complexity), TCP/IP fundamentals (structure of headers / properties of connection and connectionless protocols, hand shake, closure of connection), database (shared lock/exclusive lock, SQL statement), system stability calculation, computer science (page file basic (e.g. global to system or private to individual processes, CPU scheduling (What is the minimum unit for scheduling?, Little/Big Endian Byte Order), IPC mechanism (message queue, pipeline, semaphore), programming (mainly on interpreting the memory allocation for pointers/malloc()/array/string assignment). Question for Algorithm test: Without using standard library function, write a program that covert decimal to hexadecimal, check if the hexadecimal number is the same in forward order and reverse order (e.g. 0x3C3, 0x4B4 are the same in forward order and reverse order). HR questions: Reason for leaving? What do you think is required to be a great software engineer?  


First the HR contacted me and we made a appointment in their office. The process is not organized well, I had to go there twice becaues their technical manager was away for business trip and the HR doesn't informed me. Interview questions: 1. Given a list of numbers, find a fastest sort algorithm 2. Describe TCP hand shake process 3. Describe DB master-slave process 4. Describe the work process of a TCP proxy 5. Describe the ways to defend DDos

求解素数

## garena fungchai

Look around for other jobs.  Now is not good.

On Mon, Jul 18, 2016 at 10:10 AM, Rui <wirelesser@gmail.com> wrote:
valuable information..
thanks, how is your plan now?

On Tue, Jul 12, 2016 at 11:25 PM, LIM Fung-Chai <lim.fung.chai@gmail.com> wrote:
I add what I remember in red.  You can give to other people.

On Wed, Jun 29, 2016 at 11:34 AM, Rui <wirelesser@gmail.com> wrote:
Hugo (from Garena HR) sent me an email today about arranging for an interview at Garena for the Server Developer position.  What is the usual length for the first interview?  On average, how many interviews will there be?  Is there any full-day interview?  Do you have any advice for the technical test?  C++11?  Questions on algorithms?  Or given a problem, work out a solution with real code?  Thanks for your help.

--

Usually scenario = 1 hour paper test -> first round face 2 face(1 hour) | HR interview (30 min) (first day should be done here)-> second round -> VP (no technical question but talk about your career path, company culture, offer/negotiate)
 
 
Paper test
24 questions, (multiple?) choice + 1 programming on paper(1 hour):3 parts. First part is multiple choice.  Second part is not multiple choice. Third part is writing code (insertion into sorted doubly-linked
list)  In first part, if you don't know, guess any answer. No deduction for wrong answer.
 
1.sort,algorithm
Sort algorithm(insertion sort, quick sort, merge sort, heapsort) complexity, which has worst case N^2... Which is stable sort,
Binary tree already know inorder/preorder, figure out post-order
In-order printing of unknown binary tree is ABCDEFG, pre-order printing of same tree is C???? What is the post-order result?  From in-order and pre-order, figure out the binary tree.  Then write out the post-order answer. 
Put an array into minimum  heap result

What is the probability of getting 4 aces in a shuffled deck of 52 cards? Can write your answer using factorials 
 
2.Network
ip protocol characters(sequence number, integrity...)
What protocols are on top of UDP(choose from DNS,HTTP,....)
Tcp protocol characters (e.g. Stream, not packet boundary, high flow? Reliable? Connection oriented?)
 
3.OS
Some questions about page table, MMU, logical address length
IPC implementation
Encrypt algorithm, AES,MD5,CRC,RSA, asymmetric  or symmetric
Thread is cpu scheduler basic unit (correct or wrong?)
 
4.Database
Some question about general database knowledge, e.g. shared lock, exclusive lock, dirty read, transaction

Database with 2 tables.  
User table : user-id (primary key), user-name
Login table : id (primary key), user-id (foreign key), login-datetime
Write SQL statement that will print user's name and login time of all users who logged in after 7pm on 2 Feb 2016 
 
5.C programming
Char xx[]=”hello”, “hello” stored on stack? char *p=”test” ?(a constant section?not sure)
Sizeof(xx)=6?
 
6.Others
I can’t remember clearly
Reliable: Component R  = 0.9, R - R -R =?
and this?
R--- R - R
  |-R - R  
 
Programming
Sorted Doubly linked list - can’t remember what is it, but not difficult, something like insert node in sorted doubly linked list Insert node into already sorted doubly linked list; still sorted after insertion. Specify language that you choose.  Write your own doubly linked list or node data structure.
 
 
Face 2 face
HR: HR will ask you if you can work OT | change on project demand | work in tough time/deadline, office hour: 9:30 - 7:00 PM, don’t be too honest at this round.until you get offer.
 
Technical, it is quite tough, question range is wide as interviewee changed every time.
 
E.g.
Network programming, max connections per server port, TCP_NODELAY? Boost asio heavy used here, but better know socket API, and sync/non blocking, select/epoll..lib such as protocol buffer
 
Database, create index on multiple columns,  varchar 16 vs char 16?  Why need to create index?
 
C/C++ programming, if you say you know C++11, then general C++11 questions will be definitely asked.
 
Python, also heavy used here, was asked about decorator, some other topics surely to be prepared, like any lib you know/used.
 
Algorithm, usually asked to solve a problem(e.g. Implement tail), some one was asked dynamic programming(DP), explain how to solve knapsack problem, refer to hackerrank/leet code.
 
Malloc how is it implemented,  fragmentation merge(buddy algorithm,etc)
 
Internet practice.  E.g. Bottle neck when you design a e-commerce store(search volume is huge, transaction?), how to solve it.
 
OS, thread/process/

A user typed in a URL (eg, http://www.ietf.org/rfc/rfc2819.html) into browser.  What happens in the background?  (eg, DNS lookup to convert www.ietf.org into an IP address, lookup gateway for this IP address, ARP of gateway, etc).  Explain all the way until the browser receives the html page and then parse it, and then layout and render the html document.

Program has 2 producers and 2 consumers sharing a common queue that has a maximum capacity of 5.  That is, when the queue already has 5 items, the producers will be blocked when they attempt to insert a new item into the queue until one or both consumers remove one or more items from the queue.  Use semaphore(s) to ensure thread-safety when inserting into and removing items from the queue.  A semaphore has a non-negative value (which can be set by using = assignment) and 2 functions
   signal() - increment the value by 1 and return
   wait() - if value != 0, decrement value by 1 and return;
               if value is 0, block until value != 0, then decrement value by 1 and return.

What is virtual memory and how is it implemented?  This is OS question.

What is vptr and vtbl?  This is question on C++ virtual function, base and derived classes.

What is difference between static and shared libraries?  How is shared library implemented?

Given an array of positive integers, the array is not sorted and may contain duplicates.  For example: 1, 3, 5, 2, 3, 3.  Also given is a positive integer, say, 6.  Write a program that will return a list of pairs of integers in the array that adds up to 6, the list should not contain duplicates.  In the above example, the program should return <1, 5> and <3, 3>.  Even though A[1] + A[4] == 6, A[1] + A[5] == 6 and A[4] + A[5] == 6, the program should include only one of these <3, 3> pairs in its returned list.



##	Acronics 2015
介绍项目，有什么特别的部分，如何对自己的C++评分，哪些不足。
线程如何调度的,线程，进程的区别
一段模板函数，如何计算被实例化了多少次,利用静态变量/类来初始化同一个全局变量

int g_count = 0;
template<typename T>
void f(T x)
{
    static int i = g_count++;
}

删除vector中的元素，为何用remove/erase，为何不能直接erase (   v.erase( std::remove( std::begin(v), std::end(v), 5 ), std::end(v) );)
STL map的实现，查找复杂度，worst case复杂度O（LogN） http://bigocheatsheet.com/

Unordered_map实现，什么时候用unordered_map/stl map
MyClass obj[10]，如果第三个发生了exception,如何管理资源->?已构造的析构，未构造的不管

Mutex的实现，是不是每次都进入内核引发睡眠，和原子操作的比较, 参见linux system programming
10000个job,其中有600个counter, context switch？原问题是？ 

AB两个文件各10GB,ram=8GB，找出B中A没有的数据
-> 思路，把A用某一个hash func分割成100份文件，建立一个hashmap，然后读取B中的数据，查找是否在A中。

找出bug,design 问题,node里面含有remove
Atomic 和 mutex混用
邀请面vp of engineering, 据之

2018-01-23
what challenge->答得不好，扯了一堆其实都不是challenge，可以讲take over new technology
encryption -> AES对称, DES对称， RSA非对称 答错了
goroutine是什么， 和thread比较，和C++还有什么优势 ，忘了讲GC
bloom_filter 用在游戏里？
i=1;j=i++;r=++j;->i=j=r=2
map,unordered_map比较,什么时候用
python machine learning做了什么, cluster算法? k-means
restful api和非restful api->（Client-Server、Stateless、Cache、Uniform Interface、Layered System、Code-on-Demand）
python 函数中再给a=2赋值是否影响外部的a
A和B都是8G的文件含有n个块，找出A中的不存在于B里的block
需要做几个golang的online test -> gmailsync

//2 nd
Upper()的实现，while循环如何优化，使用一个map[256]预先保存
改用Lambda实现, text.for_each()
提到C++/Qt，版本？ 
Unordered_map什么场景，user_token -> userprofile,假如user_token 的hash计算十分复杂。




##	HRT
2016-12
introduction
python (interpret to middle language) vs c++ 
map insert complexity 复杂度  O(LogN)
unordered_map
why unordered_map
shared_ptr 用处,size - 8bytes,raw_ptr and ref_count block
reverse(input_iter) 实现 stack, - python
udp vs tcp,为什么用其中一个.
what standard library use:
python count line has string: with open(xxx) 有什么用
10 server, 每个之间都相互连接，共需多少个tcp conn, python 计算 1+2+3+4...n
regular expression 如何匹配任意字符[\\D]*

##	Quantcast
2017-08
Size of Largest possible set in array the sum no greater than K
给出一个数组，找出一个包括尽可能多元素的集合，其和小于K，返回集合的长度
集合不需要在原数组中连续
思路，对于数组问题，尽可能使用O(N)j解决

##	BAML
Introduction,why financial area,javafx,
we can directly query on website(morningstar), why need a framework? ->not free data, some special chart.

Given a table, find the maximum gap and minimum gap
       High low
MSFT   800  150
GOOGL  700  650
df[‘gap’] = df[‘high’] - df[‘low’]
休息不好，印度人的口音听不太清楚。

How to define risky of stock:option price,(marketcap)
List comprehension ->[xxx]
What is lambda
1,-1,2,-2,mean, variance, 
Taylor series exp()
Hashmap, hashtable,concurrent_hashmap, read lot/write lot, choose a better container
Clock angle: 2.15  3/4*30
What is python
面的莫名其妙

##	Grasshopper 2018-02-12
Introduction,
Lambda 是什么
Tree –preorder 就是先打印本节点。！！！shit 这个答错了
Stack unwind怎么实现的
机器学习用了什么，video tag api是什么
实现Moving average, mvg(std::vector<int> data, int window) {}
实现动态的moving average() 后面可以继续输入数据计算动态的mvg， 注意vector.pop_front()是否存在
->这个有没更好的办法? 这个保持一个总数和个数即可，比median 容易很多

怎么debug..这个问题很笼统，用debug info,看log,没有debug info呢
提及了smart ptr，问用的是什么->shared_ptr,细节,ptr to resource, use_count, weak_count等等，TBD，没问太深
比较golang，c++，python，喜欢用哪个，golang的特点，goroutine, gc,等等。




##	Credit sussie
**2018年**
先扯了下orderbook中用static 变量的问题
```
void 
assign(int*p)
{
    p = new int();
    *p = 8;
}
int main()
{
int* p;
assign(p);
cout << *p;
}
```

这道题失误了，由于分配了空间，所以可以访问，但是size为0
vector<int> v;
v.reserve( 25 );

v[5] = 8;
v[11] = 9;
for( int i=0;i<v.size(); i++ )
{
  cout << v[i] << endl;
}


leetcode 160 并非看有无cycle
find common node of linkedlist
不可以用 unordered_set 
```
while (curA != curB) {
  if (curA) {
     curA = curA->next;
  } else {
     curA = headB;
  }
  if (curB) {
     curB = curB->next;
  } else {
     curB = headA;
  }
}
return curA;
```

感觉这个解答应该是对的，不知道为什么印度人不能理解

输出，为何match第一个,如何通过模版获得array的size
```
template <class T, int S = 100> struct Array
{
    T arr[S];
    int size() const { return S; }
};

template<> struct Array<int, 200>
{
    int arr[200];
    int size() const { return 200; }
};

std::cout << Array<int>().size() << '\n';
```
原因第二个是特化，只有传入200的时候才成立


**2020/05**

可能没有顺序，整理了一下
有哪些创建thread的方式-> new thread, async,pthread_create,但是这个答得不好，有点具体忘了
mutex 有哪几种，提到了lock_guard,unique_lock,readwritelock,具体还是再去看一下比较好
design pattern,提了pimpl,command,考了singleton,答出mayer and double lock两种模式
lambda中能否返回lambda->可以
如何验证TPS能达到原来的水平->使用滑动窗口算法??? 不就是测量吗，还能什么
用C++多久了,python和C++哪个更好->C++
network programming做过吗，用了什么API->还是要去回顾一下，提一下epoll,reactor,boost async较好
如何使所有的线程都在同一个点启动-》使用promise和future,再加强
做了什么多线程的开发->这个再巩固一下,可以介绍一下yitu的人脸项目,JDSU的
用C++怎么开发microservice->其实可以提一下openresty,
具体做了什么和trading相关的东西->答了一些kingstar,个人的side project,感觉以后不要扯kingstar.另外还提了JDSU的项目，为什么是low latency,
对TCP/IP熟吗，这个还是要去看一下，起码头部，协议如何解码都要看一下，滑动窗口的概念

总结
没有问算法/容器
C++11中还是有很多没问，move,perfect forward,
auto,pthread_的API再加强一下

**2020/06/17**
解释orderbook项目
->按照readme 
为什么用decltype 来声明那个clock type
->C++14支持
为什么用auto&& xx = map.find(xx)
->其实没必要用
有什么可以在头尾插入都比较高效 - > deque
没有profiler的时候怎么做
->log,top,iostat,


##	BitMain
一致性hash http://afghl.github.io/2016/07/04/consistent-hashing.html
short video tiny url 短网址的设计，如何把短网址分区,如果要按时间提取数据呢，->就是把这些信息编码进fid中，如果数据坏了怎么备份（raid5）
payment 的用户登录密码问题
机器学习kmeans是什么，哪些cluster方式
python用了什么库，原本想问tornado,flask，我说了asyncio
C++问题，why virtual dtor, futures/promise怎么解释,atomic load/store的参数（barrier,memory model），含义
有什么新特性：扯了smart pointer,lambda, initializer list等等
cast有哪些，意思：static_cast,const_cast,dynamic_cast, reinterpret_cast等等
做题twosum,threesum
=>第一次出来面system design，比较懵懂

##	yitu
编程
1.climb stairs lc70?
2.找出能够整除的数 lc523?

HR
Self introduction,
what’s your thought about zhenjie&zhoujian’s talk.
->face recognization, medical
->company culture? compare with china?
Shanghai balbala
Why leave company?
->looking for better oppturnity, have chance to shake up company’s culture

what’s your expection in next few years.
Enjor programming, take as a piece of life.

how do you friend think about you?
->young heart


# 2019 company
## ant financial - solution architect
2019
synchronized, 如何做多个JVM之间的同步
agile讲一下
spring framework 讲一下
为什么要connection pool
design pattern了解, factory,singleton
数据库范式和反范式,定义，为何会有反范式
乐观锁，悲观锁
需要double TPS 性能,扩容，怎么做。
打开网页，网页已经加载出来了，但是很慢，怎么分析
jobA读取和写入数据，jobB做过去30天报表汇总，很慢，怎么分析

二面
自我介绍
讲项目
yitu的speechsaas,架构
AI reception,用了什么技术，
role in sea group,
beetalk 的架构
总的感觉有点扯远了，扯到了每个项目每个细节，应该给个总览
jdsu的项目，架构
项目挂，可能是没有比较概括性的思路
=>放到今天如果以AWS SA的思路去看显然好很多

## amazon
2019-3-19
coding
LC210 course schedule2
first non-repeat element [a,b,1,a,b,2,c,d]  => 1
LC124 Binary Tree Maximum Path Sum (hard)

system design 
design Netflix,start from 20user/20 video->million user/20 video->million user/million video

BQ
disagree with manager & team member.
most technical challenge
most critic feedback
can’t meet commitment
how long is the project
let you redo the project, how will you do
BQ感觉很例行公式，最好还是贴合leadership principle把故事先写下来

## goldman sachs
一面introduction略过不提
二面cloud database的好处，
设计一个报价系统，要求，多个vender,多个product,多个price
binary tree，垂直画线，看那些node落在同一个column里 lc?
kubernetes statefulset特点，hadoop特点，临近计算,比较spark的map reduce和手工制作的map reducor系统
做题，find median point of streaming data

## bytedance
1.项目介绍，spark部分,oom如何调试，
做题LRU
2.spark SQL的底层，系统侧，线程，协程，epoll,tcp closewait, web server如何调试，crash调试，c++智能指针,
做题，多个数组，找出第m个小的数

# 2019

## datarobot
2019/9/2 1面越南人 lca 1143 不幸没做出来
9/12 trie tree
```
class TypeAheaf(object):
def __init__(self):
 self.root = {}
 pass



def add(self,txt):
 curr_node = self.root
 for idx, c in enumerate(txt):
  if c not in curr_node:
   curr_node[c] = {} #TrieNode(c)
  else:
   curr_node = curr_node[c]  
 pass


def get_all_childs(self, curr_node):
 ret_list = []
 comb = ''
 self.dfs(curr_node, ret_list, comb)
 return ret_list


def dfs(self, node, ret_list, comb):  
 if len(node.childs) == 0:
  retList.append(comb)

 for key,value in node.childs.items():
  #value is trie node
  comb+=key
  self.dfs(value, ret_list, comb)
  comb=comb[:-1]

def get(self,txt):
 curr_node = self.root
 for idx, c in enumerate(txt):
  if c not in curr_node:
   return []
  else:
   curr_node = curr_node[c]
 return self.get_all_childs(curr_node)
```
9/23 project

# 2020找工作
## envision
英文自我介绍
介绍公司项目
计算平台总的架构,workflow和notebook, alluxio的用途，s3存在的问题
spark application 优化, 举个例子(reducekey)，
spark 容错是怎么做的,checkpoint 如何做的
spark架构，是如何做弹性计算的, rdd，内存计算,如何做mapreduce.

IOC AOP,用来做commonlog
JVM CES G1 垃圾处理器
synchronized reentrylock
spring 组件讲一下

另一次面试
jenkins的流程 - 定义好node,用pipeline，或者简单的job
spring 的anonation
kafka会不会有点重？
kafka的持久化，怎么保证数据可靠 (还真不知道怎么持久到硬盘，再看看)
发100万个短信，架构?

shanghai chenjian
spark 平台怎么保证运维-TODO prometheus + grafana
spark 用什么方法解决出错的问题? - 限制资源分配，限制任务过多,但是没有较好的整体调度控制
最大的挑战

sihao/devops
如何考虑数据安全
->哪个层面上，服务上有使用oauth,jwt，路由上有角色验证，数据库上有权限/role管理
有无和用户交流，收集需求，数据建模的经验?(DIA)TODO

bailing/PM
如何考虑第三方组件和自己研发
->如果第三方组件已经无人维护，那就需要慎重考虑
toB和toC业务的区别
->交付频率，用户，数据安全性，运维
我从中提起另一个话题,如何保证tob业务的交付质量
yitu使用了staging来做验证


## APPLE
product of each element
[4,3,2,1]输出 3*2*1,4*2*1,4*3*1,4*3*2 lc238
A,B,C...Z,AA,AB,AC..ZZ,AAA,已知A=1，求出AAA为多少 lc168?
**浏览器输入网址发生什么** 这个需要再看一下标准解答
https://cloud.tencent.com/developer/article/1586851#:~:text=%E5%9C%A8%E5%AE%A2%E6%88%B7%E7%AB%AF%E8%BE%93%E5%85%A5URL,%E4%BA%86%E9%83%BD%E4%BC%9A%E7%BB%93%E6%9D%9F%E6%9F%A5%E6%89%BE%E6%B5%81%E7%A8%8B%E3%80%82


https certification 硬伤 TODO
http over ssl,
tcp/ip protocol, ip header里都有什么
感觉有点扯了，IP

## DBS 
2020/5/21
CONSTRAINT : MEMORY ( MOST - IMPORTANT )
Build a cache which can store positive integers ranging from 0 to 2^32 -1 
Set : O(1)
Get : O(1)

不知道考官想问什么,很怪异
回答unordered_set<>,然后说内存太多
抛出int array[2^32-1]， 问有什么好处，现实中谁会这么做呢?
然后修改使用bit从而更小的内存.

2nd
讓你實現一個facial recognization 系統，需要怎樣設計
面得有点水，准备出offer
职位 VP, Java Backend Engineer (GAPI), Group Consumer Banking and Big Data Analytics Technology, Technology and Operations - (WD12702)

## lazada
2020/05
要設計一個KV,存1b條數據(embedding)，怎麽做,需要100kQPS
->考慮多機基於rocksdb的情況，前面放一個proxy來做分流, client sdk用python+grpc,grpc service

從kafka讀取user visit per shop, 要計算topK，怎麽做，要求一个滑动的时间窗口，比如7天内的数据，可能现在进不了TopK的话，第二天会进来，需要一個時間窗口，需要去重
例如使用32台機器，有无可能同一个user 分布在不同的机器上?如何做去重
->就是写个程序，每台机器搞个滑动窗口，同一个user 分配到同一个client上

[1,5]組成不同的數，如何判斷下一個是什麽1,11,15,51,55,111,115

maxsum lc53 反思，老是做錯!

2nd 主要是做题
lc189 rotate array e 其实还有点难想出来
lc653 two sum ,input bst e
lc297 h serialize and deserialize binary tree h

3nd
对lazada app有什么改进->这个答得一般，说了一个物流，一个选择型号字体太小了
感觉对方认为yitu主要的是单机的人脸系统，对高并发，多机有点怀疑，给他解释了这方面的经验
对阿里的技术有什么理解->小的dubbo,大的oceanbase,flint，yitu也在做类似的newSQL ,tikv

设计一个邮件促销系统
->首先最核心的是一个发送部分，输入就是用户/内容，输出就是到不同的邮件服务器，
然后在这个之上，就是两个输入，一个是用户，把对应的用户找出来，另一个是内容，通过算法把这些找出来
还需要一个A/B test，判断邮件的效果
还有一个可称为社区/内容管理的工具，比如一个一个是公众号只读的，另一个是社区，可以讨论，反馈的,这些需要专门的运营，或者seller来处理。
->邮件系统本身就有很多基础件，例如需要存储，需要缓存保证只发送一次，需要周期性，需要分布到多机，这个对高并发要求并不高
->从业务上，有权限，有模板，有脚本来把top sales拉出来，有个性化

4nd HR
用lazada/shopee吗
how to work with algorithm engineer.
stressful 环境，为何
how to start job in new company
->问对shopee怎么看
->和阿里其它的部门关系,aliexpress,ant,taobao


## OCBC
ocbc.taleo.net/ softarts/20C*
Senior Full Stack Developer, Group Operations & Technology - (200000GT)
反馈test case 太少，spring版本太旧

## thoughtworks
2020/06/12 
pair programming 有几点值得思考
需要掌握面试官的期望，要实现到何种程度
通常需要先实现一个最小的版本,但如何处理一些异常情况呢
robotvacuum构造失败的时候处于何种状态(通过异常来处理？其他都没有什么好办法,通过函数状态来处理也不是一个好办法)
对object进行何种分解,encapuslation,封装，例如，再用一个point来保存类

但是如何实现

# 2021
## mihoyo
string 拼接 ,+, buffer.writestring,strings.join,以及fmt.Sprintf，还有string builder
-> https://blog.csdn.net/iamlihongwei/article/details/79551259

并发append slice有什么副作用->slice,map 都不是线程安全，使用sync.mutex保护

select 和别的io有什么区别 (epoll?)， 都是同步io,select需要轮询多个fd,
select 可以保证顺序吗  ->不保证，两个同时被触发，随机执行一个
context可以父context退出了，子context自动退出吗 ->如果有父子关系的话，stop会连带取消下面的ctx
gc的实现, 三色,mark a
goroutine panic了，是否影响父 -> 会影响其他协程和主线程，但是如果做了recover处理就没有影响,而且是必须是该协程自身捕捉panic
如何从多个goroutine通信, pattern? -> channel?
如何在不同线程间传递消息, channel
channel关闭了，发送会panic，但是接收会收到对应类型的空值
使用select+channel来关闭goroutine
lc862 - hard 如何优化，需要一些预计算结果，使用sliding window

2面
讲一讲线程，协程
某个线程特别忙，怎么debug->pidstat
哪些信号不可以被捕捉，信号是怎么传递给进程的-->通过软中断信号进入内核, 内核处理一个进程收到的信号的时机是在一个进程从内核态返回用户态时。所以，当一个进程在内核态下运行时，软中断信号并不立即起作用，要等到将返回用户态时才处理。进程只有处理完信号才会返回用户态，进程在用户态下不会有未处理完的信号。（ksoftirq??在进出内核的时候会检查?）
如何快速的禁掉某个ip,->iptable
为什么goroutine这种方式比以前的1thread per request要好
如何解决服务依赖问题->aws cloudformation template,iaac,terrform
网络包的处理过程-> 
https://www.cnblogs.com/muahao/p/10861771.html
device->driver ring buffer
在软中断时，net_rx_action会调用napi_struct结构的poll钩子函数,将数据包从驱动传到网络协议栈。->netif_receive_skb()将sk_buff上送协议栈
中断分为上半和下半


http 的协议是如何的，怎么知道长度->参考图解http协议一书
https有什么用，证书是如何起作用的  TODO
CICD，灰度发布的过程  -> aws codedeploy, blue/green, all-at-once, canary, linear
编程 left view lc513,199

**go的debug**
这次问题 gdb 和 Golang 的 pprof 工具库帮上了大忙。尤其是 pprof。对于有 HTTP 服务的服务器 Go 程序，使用 pprof 非常简单：直接导入 pprof，就能够在默认的 HTTP 服务上注册一个新的路径作为调试：
import (
    ...
    _ "net/http/pprof"
)
然后 HTTP 服务启动之后便能通过浏览器或者 curl 看到 debug 输出。如下是输出程序中所有 Goroutine 的 backtrace：
curl localhost:10000/debug/pprof/goroutines?debug=1

还可以通过runtime.stack获得stacks，做法，建立一个signal handler,然后发送信号，在此handler中输出stack

**go gc/runtime**
https://www.bookstack.cn/read/qcrao-Go-Questions/spilt.13.GC-GC.md 
无分代(做了逃逸分析)，不整理(java的G1有碎片整理，go用的tcmalloc无碎片问题),并发3色标记(波面推进)，写屏障(在STW过程中造成污染，该写屏障会将被覆盖的对象标记成灰色并在当前栈没有扫描时将新对象也标记成灰色)
3色标记缩短了STW,
协作式协程,对于紧循环无法调度，1.14之后有优化
调优,关注cpu利用率,停顿时间，参数GOGC
工具 pprof/trace来看, go tool pprof/trace


## scb 2021
sabre
1面
创建一个cache+extsystem,
1.对于同一个key，同时只能有一个在调用外部系统
2.对于不同的key，允许并发访问

2面
比较arrayList和linkedlist
->连续内存和new新对象的区别
内存上linkedlist更消耗50%，所以一般的append应该用arraylisty->答得不好

给出一个person，改写hashcode=1，是否影响？
如果name="mike"都一样，是否会overwrite，->如果不override equals的话，默认是a比较object.equals(比较erference)而已，切记

volatile什么意思
atomic 同步手段
top,netstat, memory usage,
gdb debug java application，能否看到stack?

//TODO
computeAll(List<Integer> result) {
  //执行长时间运行的task
  //tight loop
}

todo 能否连续用两个map来形成管道？collect(Collectors.toList())
可以用parallelStream()->更方便,但是线程数是多少？(-1)
能否中断
如果有future的可以中断
parallelStream如何中断？forkjoinpool?
terminate, future.cancel?
对数据库的了解,JPA,spring python+mysql api
/var/logs,/var/message

3面
介绍，对GC的认识，用什么版本->CMS,G1,ZGC,C4
fail fast 和fail safe?->collection 不知道，快速失败和快速恢复，这个问题不是太好,程式化,fail-safe会复制一份集合，保证不受影响
cohension & coupling->类设计应该是高凝聚性和低耦合性
decorator?->hook
production hang,uat正常，如何debug,无法提供threaddump的情况，感觉这里废话多了点，说什么ssh connect,使用jstack,pstack,看code,isolate,考虑production traffic,
spring bean lifecycle, 这个问题问了两遍，需要看一下,为什么要这个管理
register,precreate,post create
了解docker／kubernetes 的概念，简单带过
4 pod,访问同一个kafak,设计，如果replica factor=2，那么就是8个partition,每个consumer连2个partition
在threads之间共享数据->回答了使用synchronization，但是可能没到位，还要答volatile, atomic


**platform**
1面
问的很泛, what happen when browser open url
mq semantic->简单回答了exact-once & at least once
create docker image
kubernetes concept, stateful, deployment
java high performance programming->随便扯了下JVM
alb vs nlb，为什么要在layer7做load balance
elk experience -> 使用
monitor/logs/tracing experience->appdynamic, open jaeger
如何debug网络问题?tcpdump, netstat?

2面
dependency injection的概念，有什么好处->spring 提供factory pattern,不需要自己来创建bean,但是感觉spring这里还是要理一下
design pattern 来处理不同的product type->command pattern?dispatcher
mock,stub的区别->ok
forward & reverse proxy
why persistent http connection?->server assume client want to keep connection unless "close" in header (connection:keep-alive)
protocol 兼容性，新增加field的时候怎么办？protobuf, json?raw content->
docker 里面的init-container用来初始化mysql
http authentication 安全的做法->oauth/basic oauth，如何为不同的route配置不同的安全属性
如何做code review->几个层面，system,application, coding
如果一个app返回504（Gateway timeout）,怎么debug?-> app dead?答得不是很好


**digibank**
coding assessment,纯粹spring collection
CTO 纯聊天
cloud native env，分为devops,tester,datascience,mobbile,UI, 还有几个scrum master
即将build第一个版本,从mox拿过来，但需要改造mox，没有mainframe
agile mode,cheap cost,走monzo的路线
->简单介绍了dbs，再提了下之前tech公司的技术栈，但是CTO问了个问题似乎没听明白，讲了一堆如何deployment pipeline
we build we run的东西，有点混乱
突出了自己有aws cert,同时做题时的一些缺陷

**offer**
base 175k(14.58), bonus 37k, benefit 3k, 
->base 185k(15.41),benefit 3.7k, bonus 38k ->226.7
exp: 192k(16)


## squarepoint 2021
过简历，实现vector,member_variable 的命名方式,copy assignment,ctor, exception 等

最大感受，有段时间没做了，c++ server side没什么底气，

问做过什么c++项目，有点弱，要加强这个，就说boost asio server
讲sea 的project时，做windows client, windows server/linux server不是自己做的
转去做golang server

如何optimize system, linux-perf, framegraph，没提，可惜,这里有点瞎问，每个project的目标都不一样,latency


## goldman sachs
就是做题
1. union， 给出一批edge,判断一个forest有几个root
2. 实现 hashmap

## bytedance
### speech 
**1**
cloud native有什么了解,这个太抽象了，加强了cloudnative java 这本书
围绕yitu的项目,saas,但是说不了解训练这块
mysql和oracle的区别,这里展开讲了下rocksdb,LSM,WAL，但是太粗浅
B/B+树，rocksdb，这里要是能多看一下加强一下就行了, B+与B区别
ORM用了什么，JPA
题目 lc33，可惜没练好，失败

**2**
2个小时，问了很多东西
有没带人，职业目标，带团队有什么想法
c++
allocator(TBD), shared_ptr的组成,ref count用什么实现(原子变量),new/delete的三种使用
python, decorator, 多进程如何启动(process包)
java, weakreference
go channel的实现是什么->blocking linked queue
grpc底层是什么(http/2),pb的字符串?string 流 应该是stream, 参考在这里
https://github.com/grpc/grpc/blob/v1.40.0/examples/protos/route_guide.proto

reddis有什么数据类型, zset,set,string, list, hashmap,zset是跳表(skiplist)
跳表的实现->多级索引

给出一个语音的架构->输入流,IO复用，app server, asr, 打标点，rabbitmq,object store
是否参与了端到端的实现->2019年实现了短语音的部署
实现了什么功能,实时上屏的延时如何，如何打标点，长语音最长多少(300分钟)
实时语音的接口如何,GRPC->使用客户端

用过什么中间件, mongodb, kafka, rabbitmq,tidb,mysql,
rabbitmq和kafka 的区别; mongodb的索引类型??
gateway应该实现功能->路由，认证，鉴权, 适配，多版本，不同用户的流量方案

rest的特点->无状态，资源，方法，另外还有cacheable,描述性，状态码

做题
lc001, twosum, 两种做法，还有quicksort实现

问题
有什么组->实时上屏，教育，

**3**
自我介绍
为何用rocksdb，和其他的比较如何->
LSM结构来追加数据，通过后台线程来合并数据,build一个多级的memtable-ssdtable，查找是逐级查找,每个ssdtable对应不同的范围，越往下数据越旧越多，每层之间有重叠，合并压缩数据后写入磁盘，转化为顺序写，改善写的性能，但重复的写入同一个数据会放大写开销，特别是大的value.
性能上要求20k,是技能达到50k-100k，mongodb的部署方面比较麻烦
和intel傲腾nvme ssd性能非常好，另外自行增加feature也比较方便(都是废话，我就觉得vs mongodb 没啥优势)

sea->yitu(产品失败) yitu->dbs(公司关闭), 体验一下dbs的金融环境。为什么要从dbs出来
->字节做的比较好，本身比较熟悉这个产品，另外要找些挑战,喜欢互联网的环境

你在新的role上有什么期待?
->1.solution design 2.deliver product,过去一年在leadership,招聘上做了很多东西，觉得具备了这两个能力，可以胜任这个职位，teamwork，可以提高生产率
对带team有什么体会

举个例子，在yitu是怎么交付端到端的产品
->最早是小程序亮相,然后确定产品线,和交付指标，接下来是自顶向下设定架构设计，API设计,实现。中间走了弯路去做混合部署，平台迁移到k8s上面,最后确定了金山用户bigo后，通过CICD来保证交付质量
回顾->对于每个集成的组件需要验收保证质量，对于交付需要建立基线保证质量
SRE,可以通过采集异常数据来反向修复产品

->对于monitor，服务治理，CICD有什么想法
监控和服务治理理解是非常难的部分，app侧需要覆盖足够的metrics
系统上可以使用APM工具,appdynamic,
trace利用ELK，opentrace，cloudfoundry的traceid来跟踪,但DBS缺失了很多关键组件
CICD->主要是流程问题，明确发布的branch,然后每个PR自动触发unit test,scan,deploy/performance的过程，提到了当时在yitu和华为合作的AI产品就是一个晚上自动完成了所有配置的测试

应用:教育，审核，实时字幕，语音合成(TTS),对话合成

**4**
ma zejun
自我介绍->dbs项目,网关，DBS之前在互联网公司，sea group, yitu, AWS solution architect证书，上个月刚刚拿了另一个aws developer，还没有更新简历

yitu新加坡的几个项目-> 做三大块, 算法落地／工程, 训练和数据平台， 贴身服务/KV存储,本地的应用dialogflow+人脸
如何和国内的算法组协调-> 对齐开发计划，确定要发布的release.和北京的算法迭代速度比较慢
上海的话就比较快，项目推进上研发总监把握宏观上的方向（比如2周一个迭代），下面具体的feature都是developer 来决定的(以及参考了PM来自市场的需求), (初期需求比较粗糙，后来发布之后就细腻很多,etc)
数据平台，部署在外场，单节点，主要做数据ETL，清洗，存储，查询，训练，基于k8s+spark
KV, rocksdb, mongodb调查，比较，20k->50k vs GRPC 100k的性能,balabala

针对语音项目，做了什么优化->
原先的SDK比较粗糙，甚至不是线程安全的，->这属于工程化的步骤(幸好这里及时修正)
将单个APIcall改成batch方式，尽管带来一点延迟，提高了吞吐率，从几路提高到近100路
decode解码方面不再需要将整个模型加载到内存，而是一个动态二次查找的过程(这里没细问...),还有将原先的单点API进行拆分，将CPU密集的部分作为单独的服务，其它的就可以尽可能复用。
从架构上讲改进->最初的spring+服务注册的结构改成k8s部署的云原生的结构，以及用rabbitmq替换kafka，还有tomcat调优(简单)

yitu 的现状-> 走掉了3/4的人，很多2017年的核心员工都走了，但是核心的力量还在,上市失败,其他三家都在pipeline里面

sea的产品线-> 游戏比较赚钱，电商为主，19年之后有自研的绝地求生，也占了不少份额，在上海有一个团队，电商在19年超越了lazada.支付则是顺带着起来(还没有license??!!)

和组员如何沟通管理-> 焦点会在junior developer上，目标设定，技术方向上的沟通，一方面是提高技术水平，另一方面帮助其职业发展，认清技术路线，对于senior developer
经常会讨论架构，策略上的问题，从而参考这些讨论为整个组织定目标，另一方面也可以向自己的老板反馈，老板下面还有其他组，帮助其横向扩展，作出合理的策略，判断,还有每个季度的沟通
team的结构,3个full time, 1个contract，还有一个在印度，6月时reorg，变成3个full time，但是考评都划到我老板那里了，当然会参考我的意见
还负责面试工作，去年到今年大概面试了30多个人，找了2个

几个职业切换的考量 -> agilent 电信行业，夕阳行业，竞争对手，丢掉了大客户之后就比较简单, 15年进入互联网行业,主要是社交产品没有做起来，最后觉得有点烦／心灰意冷,而yitu当时是AI四小龙,但是yitu 2020年开始收缩，但是人脸和语音的技术指标还不错，系统集成上没有拼得过大华，海康之类的集成商，没有将AI转化为优势，组被关掉， 现在离开DBS寻找机会，主要是比较适应喜欢互联网文化，对本产品比较熟悉，找些有挑战性的工作之类,(在DBS造了很多轮子, 部署平台甚至没有监控工具), 成就感，从零开始打磨一个产品，到能够交付给用户会有成就感
学习型的人，比较适应新环境

提问->
role scope, 3-6个月内需要deliver什么东西，
内部还是外部用户 ->抖音
和国内的写作方式->希望是同一个code base

->存粹看运气了，希望好运, ->挂了

### 基础架构
**1面**
设计一个朋友圈
table
可以放在缓存
1. userid, curpos,lastpos
2. postid, like (set)
3. userid, friendid
4. userid, postid, content, timestamp
5. postid, commentid, comment, commentor

service
post 
- new post -> get friend list Tbl3, compare with Tbl1 -> MQ job -> consumer, to send notification 
- like post -> update Tbl2 (cache)
- get post list
- get post by id Tbl4 (update Tbl1)

comment
- new comment (tbl5)
- get comment list (tbl5), filter out non-friend (compare with Tbl3)
- delete/edit my comment (tbl5)

notification
- consumer take job from kafka

infra
- mysql
- redis
- s3
- kafka
- API gateway
- load balancer
- ecs/k8s
- grafana/pothemeus/fluentd

scalibility
- mysql 水平切分
- NoSQL (TIDB, mongodb, aerospike, )

**2面**
英文介绍, 优点-> 1.aws solution, 2.broad tech stack, 3.problem solving skill
有全球各地支付用户，如何设计架构-> 多地多活（aurora, 多master,异步方式备份数据,不需要切换数据库failover，客户端直接改写的master）；单写(single master)多读，只读副本和备份， 
->思考：如果一个用户同时在两个不同的master 写入了不同的数据，如何同步？(使用read-after-write consistency，或者强一致性，对性能有影响)

如果某个机房挂了，如何切换流量->API gateway重定向, route53根据地理位置做流量分配,在client侧放入路由选择代码(配置通过服务器更新)
API gateway(路由，多版本，transformation/mapping), load balancer(服务注册), service/k8s

API gateway容量如何设计->
推送系统如何容量设计， 每秒的数据，需要的发送时间，消息长度，得到存储容量和QPS需求，发送侧到接收方可以使用RPC(avro,messagepact, pb)来包装消息
存储选型,kafka/rabbitmq，

TODO 从网卡数据如何到用户侧-> 上半下半, net_action_rx 将数据包在下半从ringbuffer->skbuff, ring0->ring3 再复制到user space
做题，得到duplicated data sum


## deutsche 
abstract vs interface，能否不用abstract，只用interface, 没准备过，有点乱答了,is-a, has-a, 
=>本质有区别，interface 可以实现多个接口, abstract method;abstract 可以有default method, non-abstract method

为什么要重新实现equal?也是乱答，不过基本就是需要比较content，不只是reference
hashcode,equal，能否只用random generated hashcode?使用xor-shift的方法
上面几个答得有点混乱，但是觉得应该不影响大局
=> object.equals default reference==

arraylist 和linkedlist 的区别，complexity
collection- arraylist, arraydeque, linkedlist,hashmap,linkedhashmap等等
treemap如何搜索





# 2022 的面试
ubiquant 九坤
笔试 lc198,36,以及一个IPC,两个service同步的设计题

2面
自我介绍->经历，技术栈
kv项目介绍一下->对rocksdb的二次开发，基于grpc做了网络层，集群规模，这里扯了半天grpc(TODO**补充点grpc的信息**)
=>最近没有多少关于c++的项目，一直提kv是否合适??**是否整理下语音项目**
写过的socketserver是什么->核心是一个视频直播,上面基于protobuf封装了command和data两类数据，视频走udp(TODO**这里补充一点boost asio的信息**)
对内存使用的理解->开始扯了一堆tbb的内存对齐,false sharing,裸指针，内存corruption，自制memory pool,tcmalloc的问题,还有最近在上层的jvm的调优（另一个角度),针对高频和中低频的优化也不一样TODO**这个有点难写**
对跳槽的看法->对行业公司看好，对自己也有利
对工作压力的看法->早上还在交付，依图卷
爱好，特长->瞎扯
夏普比率和最大回撤->说成是和beta的对比，其实应该是无风险资产及波动性，还提了下option，多因子，深度学习, cluster聚类,macd,这块讲得有点过头了，应该再谦虚点
关于quant平台->自由展开讲了下,quantopian,指出backtest更为重要，但都属于自由发挥扯谈，很难说对方接受度如何

算法题类似 lc210 courseschedule,但是没有给定义，写得还行

# 数据库

Some question about general database knowledge, e.g. shared lock, exclusive lock, dirty read, transaction, 乐观锁，悲观锁

## ACID
原子性 一致性 隔离性 持久性

## 乐观锁悲观锁
例如多个用户同时并发在一个短视频评论时，他们需要
1. 拿到ArticleID和评论数字
2. 插入对应的Comment
3. 更新评论数量保存到数据库
由于他们是同时在步骤1拿到的评论数量，所以在第三步更新的评论数+1是错的。

**乐观锁**

乐观锁顾名思义就是特别乐观，认为自己拿到的资源不会被其他线程操作所以不上锁，只是在插入数据库的时候再判断一下数据有没有被修改。所以悲观锁是限制其他线程，而乐观锁是限制自己，虽然他的名字有锁，但是实际上不算上锁，只是在最后操作的时候再判断具体怎么操作。

乐观锁通常为版本号机制或者CAS算法
```
JPA
@Data
@Entity
public class Article {   
    @Version
    private Long version;
}
其它都一样,修改失败直接抛出异常 ObjectOptimisticLockingFailureException
// CommentService
public void postComment(Long articleId, String content) {
    Optional<Article> articleOptional = articleRepository.findById(articleId);
    article.setCommentCount(article.getCommentCount() + 1);
    articleRepository.save(article);
}

或者手动增加column version
public interface ArticleRepository extends CrudRepository<Article, Long> {
    @Modifying
    @Query(value = "update article set comment_count = :commentCount, version = version + 1 where id = :id and version = :version", nativeQuery = true)
    int updateArticleWithVersion(Long id, Long commentCount, Long version);
}
```

**悲观锁**
需要查询的时候把该行锁住
使用lock或者SQL中加入FOR UPDATE
```
JPA 
public interface ArticleRepository extends CrudRepository<Article, Long> {
    @Lock(value = LockModeType.PESSIMISTIC_WRITE)
    @Query("select a from Article a where a.id = :id")
    Optional<Article> findArticleWithPessimisticLock(Long id);
}

或者Query中手动加入 for update
public interface ArticleRepository extends CrudRepository<Article, Long> {
    @Query(value = "select * from article a where a.id = :id for update", nativeQuery = true)
    Optional<Article> findArticleForUpdate(Long id);
}
```

**实践**
一般来说是两步操作,1.取得数据，2 该数据+1(或者其他操作) 3.写回数据库
这个过程需要加锁
如果说直接把数据写回去，好像不需要，写的时候会带锁,不可能出现分别写一列的情况


## 四种隔离级别
https://blog.csdn.net/fanrenxiang/article/details/102650127

级别
 1. 未提交读(Read Uncommitted):事务中的数据修改，即使事务未提交，对其他事务也是可见的。事务可以读取未提交的数据，也称为“脏读”。
 2. 提交读(Read Committed)：事务开始时，只能看见已提交事务的修改。换句话说，一个事务从开始到提交之前，所作的任何操作对其他事务是不可见的。但是如果在事务执行过程中，有其它事务提交修改，那么前后两次读取相同记录的结果不相同（不一致），也称作不可重复读（nonrepeatable read）受其他事务影响
 3. 可重复读(Repeatable Read)：事务中前后两次读取相同记录的结果是一致的，即使有事务提交。(不受别的事务提交的影响)。可重复读可以解决脏的问题，但是存在幻读（Phantom Read）的问题,当事务在读取某个范围内记录的时候，如果另外一个事务插入了新的数据记录，之前的事务中再次读取该范围内的数据记录，那么将会产生幻行（Phantom Rows）。InnoDB通过使用多版本并发控制MVCC解决了幻读的问题。   --不受其他事务影响，但是如何更新数据？
 4. 可串行化(Serializable)：事务串行化执行。


常见的几个问题解决方案
1. 脏读 ->1 使用level2
2. 不可重复读  ->开启事务后会看到2次不同的结果,事务A在事务B提交前后读取到不一样的数据 (默认)
3. 幻读 ->MVCC 3 (与2相比侧重于innsert/delete操作)
4. 何为幻行?



## 锁
个人认为锁与事务的隔离级别不存在任何关系，但是我们有时候经常被这两个概念弄混淆。
锁与事务隔离级别都是为了保证在多线程并发环境下，数据访问的安全性。当时事务交叉执行时，如果不设置事务的隔离级别(事务存在还有意义吗？)，那么数据将会被不同事务轮访问和修改，执行结果无法预期。

读锁（共享锁）：相互不阻塞，可以在同一时刻读取同一个资源，即在同一个资源上可以同时添加多个读锁。
写锁（排他锁）：阻塞其他读锁或写锁，独占资源，在给定的时间内只允许一个用户写入。
锁粒度：加锁对象（资源）的大小。锁粒度的大小影响的系统的并发性和系统开销。当锁粒度较小，可以提高资源的并发使用，但是也增加的系统加锁的开销。反之，锁粒度越大，并发度越低，
表锁（table locks）：在整张表上进行加锁，如MyISAM引擎。
行锁（row locks）：在表中的一行或者多行数据记录上加锁。
页锁（page locks）：目前只有BDB存储引擎使用。
元数据锁（Metadata Locks）：MySQL5.5中引入，应用在表的metadata上。当一个线程使用表的时候，将会锁定整张表的metadata信息，不允许其他线程修改表结构。


1、加锁与解锁时机：当开始执行SQL，将会对一些数据进行加锁，如整个表，某些行，metadata信息。当sql执行完成，将会解锁，其他线程就可以开始申请使用资源。
2、MySQL事务特性是由存储引擎提供的，如常用的InnoDB。一个事务由一个或者多个SQL组成，事务的隔离性进一步确保在多线程并发环境下数据的安全访问，直接决定事务中sql修改的数据在提交之前是否对其他事务是否可见。


## SQL
Join的类型(CCT)
[cct] p232
Inner-join 交集
1 INNER JOIN: Result set will contain only those data where the criteria match

2 OUTER JOIN: OUTER JOIN will always contain the results of INNER JOIN, however it can contain some records that have no matching record in other table OUTER JOINs are divided to following subtypes

2 1 LEFT OUTER JOIN, or simply LEFT JOIN: The result will contain all records from the left  table If no matching records were found in the right table, then its fields will contain the NULL  values

2 2  RIGHT  OUTER  JOIN,  or  simply RIGHT  JOIN: This  type  of  join  is  the  opposite  of  LEFT JOIN; it will contain all records from the right table, and missing fields from the left table will contain NULL If we have two tables A and B, then we can say that statement A LEFT JOIN B is equivalent to statement B RIGHT JOIN A

## 索引
B+tree,Btree,hash 索引  r-tree, full-text
聚集索引，指的是数据存储方式,innodb就是同一个结构中保存了b+tree索引和数据行

hash索引只能精确匹配
B+tree，数据都在叶子节点，并且叶子结点之间有链表链接
innodb使用聚集索引，把数据和索引存到一个叶子页里16k
辅助索引(非聚集索引) 需要回表

B+ Tree索引和Hash索引区别 哈希索引适合等值查询，但是不无法进行范围查询 哈希索引没办法利用索引完成排序 哈希索引不支持多列联合索引的最左匹配规则 如果有大量重复键值得情况下，哈希索引的效率会很低，因为存在哈希碰撞问题

面试官：刚刚我们聊到B+ Tree ，那你知道B+ Tree的叶子节点都可以存哪些东西吗？
我：InnoDB的B+ Tree可能存储的是**整行数据**，也有可能是**主键**的值。
面试官：那这两者有什么区别吗？ 我：（当他问我叶子节点的时候，其实我就猜到他可能要问我聚簇索引和非聚簇索引了）在 InnoDB 里，索引B+ Tree的叶子节点存储了整行数据的是主键索引，也被称之为聚簇索引。而索引B+ Tree的叶子节点存储了主键的值的是非主键索引，也被称之为非聚簇索引。

面试官：那么，聚簇索引和非聚簇索引，在查询数据的时候有区别吗？

我：聚簇索引查��会更快？

面试官：为什么呢？

我：因为主键索引树的叶子节点直接就是我们要查询的整行数据了。而非主键索引的叶子节点是主键的值，查到主键的值以后，还需要再通过主键的值再进行一次查询。

面试官：刚刚你提到主键索引查询只会查一次，而非主键索引需要回表查询多次。（后来我才知道，原来这个过程叫做回表）是所有情况都是这样的吗？非主键索引一定会查询多次吗？

我：（额、这个问题我回答的不好，后来我自己查资料才知道，通过覆盖索引也可以只查询一次）

科普时间——覆盖索引 覆盖索引（covering index）指一个查询语句的执行只用从索引中就能够取得，不必从数据表中读取。也可以称之为实现了索引覆盖。 当一条查询语句符合覆盖索引条件时，MySQL只需要通过索引就可以返回查询所需要的数据，这样避免了查到索引后再返回表操作，减少I/O提高效率。 如，表covering_index_sample中有一个普通索引 idx_key1_key2(key1,key2)。当我们通过SQL语句：select key2 from covering_index_sample where key1 = ‘keytest’;的时候，就可以通过覆盖索引查询，无需回表。

**回表**


### 创建索引的时候都会考虑哪些因素呢？

我：我们一般对于查询概率比较高，经常作为where条件的字段设置索引
面试官：那你们有用过联合索引吗？
我：用过呀，我们有对一些表中创建过联合索引。
面试官：那你们在创建联合索引的时候，需要做联合索引多个字段之间顺序你们是如何选择的呢？
我：我们把识别度最高的字段放到最前面。


## 范式
第一范式 每个字段不可再分? Each table cell should contain a single value. Each record needs to be unique. 每一个column只能有一个value

第二范式 首先是 1NF，另外包含两部分内容，一是表必须有一个主键；二是没有包含在主键中的列必须完全依赖于主键，而不能只依赖于主键的一部分。 
考虑一个订单明细表：【OrderDetail】（OrderID，ProductID，UnitPrice，Discount，Quantity，ProductName）。 
因为我们知道在一个订单中可以订购多种产品，所以单单一个 OrderID 是不足以成为主键的，主键应该是（OrderID，ProductID）。显而易见 Discount（折扣），Quantity（数量）完全依赖（取决）于主键（OderID，ProductID），而 UnitPrice，ProductName 只依赖于 ProductID。所以 OrderDetail 表不符合 2NF。不符合 2NF 的设计容易产生冗余数据。 


第三范式 将第二范式中的传递依赖去掉，比如原来:学生号-系-系主任，其中系和系主任之间又有依赖关系，改为:系-->系主任挪到一个新的表里
第三范式（3NF）：首先是 2NF，另外非主键列必须直接依赖于主键，不能存在传递依赖。即不能存在：非主键列 A 依赖于非主键列 B，非主键列 B 依赖于主键的情况。 
第二范式（2NF）和第三范式（3NF）的概念很容易混淆，区分它们的关键点在于，2NF：非主键列是否完全依赖于主键，还是依赖于主键的一部分；3NF：非主键列是直接依赖于主键，还是直接依赖于非主键列。


### 反范式
Denormalization[cct]
[cct] p234
通过产生冗余数据来优化性能
第3范式
Denormalization is the process of attempting to optimize the performance of a database by adding redundant data or by grouping data In some cases.

A normalized design will often store different but related pieces of information in separate 
logical tables (called relations) in different physical disk

读性能提高，写性能降低，可能引入额外的constraint来保证数据一致性

**store procedure **
```
mysql> DELIMITER //
mysql> create procedure usp_GetEmployeeName(IN id INT, OUT name VARCHAR(20))
    -> begin
    -> select emp_name into name from employee where emp_id = id;
    -> end//
Query OK, 0 rows affected (0.52 sec)
 
mysql> DELIMITER ;
 
mysql> call usp_GetEmployeeName(103, @name);
Query OK, 1 row affected (0.05 sec)
```

## modern db
- rocksdb 32threads get 290k,set 160k,scan 45k
- rocksdb,value=100k, 32threads, get 38k, set 1.44k
- tikv  32threads get 80k,set 22k,scan 2.1k
- faucon value=1k, 32t, get 38k, set 10k, 
- faucon 语音组实测, 32t, 15-20k
- mongodb,value=1k, 32t, get 54.5k,set 20k,
- mongodb, value=100k, 8threads,get 7.5k, set 4.3k
- mongodb, value=100k, 32threads,get 24k, set 4.68k
- tikv-python-client size=1k,多进程32~48, get 80-90k,set 32-33k
- tikv-python-client size=100k,多进程32~48, set 0.99k


**GRPC**
纯grpc
client treads, conn,qps
32	1	68.84
64	1	71.77
128	1	75.65
256	1	75.66
32	2	82.906
64	2	88.24
128	2	87.79
32	4	65.43
64	4	78.672
128	4	94.07
256	4	108.658

使用32 client threads, 2个GRPC conn,可以到get 71k,set 47k

Faucon client 性能总结
多进程，多个grpc链接能够提高QPS
python-client在多线程（多于2）的时候,并不能有效的提高qps
faucon put的性能较低可能是由于默认代码需要多一步检测key是否存在
目前使用方式都是用户自行对faucon client进行封装，性能未必达到最优化




### rocksdb
RocksDB 中有三个基本的数据结构概念：memtable, sstfile 和 logfile

memtable 是个内存数据结构，新写入会插入memtable 切回选择性地写入logfile。
logfile 是一个顺序写入磁盘的文件。
当memtable 写满后，会flush 至盘上的sstfile，告知logfile 可以被安全地删除了。 为了让查找keys 有更好的性能，sstfile 中的数据已排序。
对RocksDB 的每次写操作都必写到两个地方：
1）基于内存的数据结构memtable（达到quota 后会flush 至SST file）。
2）预写日志-Write Ahead Log（WAL）。
如果出现异常情况，WAL 可以用来完整恢复memtable 中的数据，恢复db 的原有的状态。默认配置下，RocksDB 通过每次用户写之后flush WAL，来保证进程crash 后的一致性。

### B+ tree
leaves store the value
leaves chain as list
O(N)写入，但是read entire block,(SSD has to erase entire block)

### LSM (level-DB)
首先写入oplog, 然后memtable full了之后，swap一个新的
L0,L1,L2几个层次，每一层都进行压缩
查询,使用bloomfilter

还有几个点
skiplist
secondary indices,lucene,bkd tree,trie tree
MPP - massively parallel processing
spatial database - LBS, geohash
time-series database

# 分布式
CAP




# 技术问题备份

**Technique 常见问题**
What is  atomic operation
An atomic operation is a sequence of one or more machine instructions that are executed sequentially, without interruption. 

shared_ptr and unique_ptr threadsafe
when run move ctor, unique_ptr need to release the old ownership, it is not thread-safe
shared_ptr same, ref count and pointer not atomic operation

**Boost用过的组件(TBD)**
shared_ptr
scope_ptr
intrusive_ptr
unordered_map
property_tree
function/bind
lock free FIFO
static_assert
要求每个都要写出代码




**Most challenge in performance optimization**

**What does your current role and responsibilities entail?**
Lead developer in system phase2 project.
Develop a new protocol processing module.
Monitor system performance at customer site daily.
Solve the customer’s complaint quickly.remote debug, performance tuning and fixing.
Corordinated different people to meet user’s needs

**What is trick part in your project**
Original one is to gernerate c-style, process oriented source code, new approach is to generate an object-oriented c++ source code. And further more, Each decode field can be represent by class, and the class is linked with each other via a tree.so we have a decode tree for each protocol. the benefit is, it can easily jump from one node to another node when it is doing decode,  the other one is I can create a specifical optimization for some class.e.g decode field length < 64 bits. Thirdly, the tree has status and can keep it in memory, we can do a partial decoding and start from the last position later. This is called on demand decoding.


**What is your experience in objected oriented design and multithreaded programming?**

My opinion:
To maximum parallel performance, minimum shared data usage.
Prefer high level building block, like concurrent queue to low level synchronous(mutex/cond > semaphore/r/w lock)
Prefer lock based/atomic code to lock-free code(CAS).


##	Experience in development high performance low latency
http://codedependents.com/2014/01/27/11-best-practices-for-low-latency-systems/

choose right language;keep all in memory;keep data and processing collocated;keep system underutilized;keep context switch minimum;keep reads sequential;batch write;respect cache;non blocking as much as possible;async much as possible;parallelize as much as possible;

my thoughts from my project:
it is very big topic. I’d like to share some experience from my project.

IO part
Basically Our system is a IO & CPU mixed system. So it is most important to separate IO & CPU task. To make all cpu busy(<80%,underutilized).

Before 2010, we use the traditional API to copy packet from nic to user space.which consume a lot of CPU (>40% cpu)

2012 Implement a kernel driver to directly move packet to user space(DMA) (CPU <5%), bypass kernel and zero copy

2013 further reduce CPU usage in packet capture. choose a dedicated napatech NIC(multiqueue,10Gx2 port),support multiple stream,CPU -> 0


Another IO part is IPC between BOX.
tune kernel parameter to maximum tcp stack performance.(max fileid to support concurrent access).use raw socket API, non block socket,scatter IO write/send. Poll = select, synchronous mode

2014 changed to use boost asio, asynchronous mode. One event loop to achieve high throughput

Thread mode
Split data into 16 stream, each data stream is irrelevant to each other.memory allocation is cache alignment.(to avoid false sharing)

So we have 16 pipelines.set cpu affinity to bind cpu and thread.(to minimum context switch)
Try to make all data processing stage colocated at same cpu(to make cache hot), 

Others 
minimum queue use(cool data), choose right queue SPSC or MPMC.(lock free / lock based)
database access, use RCU cache to sequence read and batch write.(google level db 100k tps)
Evaluate  Memory pool/in-house, tcmalloc,jemalloc, tbb malloc,

## FX
Option strike, call/put ,straddle,strangle,butterfly,bullspread,
NDF (non-deliverable fx) 

DEFINITION of 'Non-Deliverable Forward - NDF'
A cash-settled, short-term forward contract on a thinly traded or non-convertible foreign currency, where the profit or loss at the time at the settlement date is calculated by taking the difference between the agreed upon exchange rate and the spot rate at the time of settlement, for an agreed upon notional amount of funds.

##	加密
对称钥匙加密系统是加密和解密均采用同一把秘密钥匙，而且通信双方都必须获得这把钥匙，并保持钥匙的秘密。
非对称密钥加密系统采用的加密钥匙（公钥）和解密钥匙（私钥）是不同的。

DES-可逆的对称加密算法,衍生出3DES
AES---它是一种高级加密标准，也叫Rijndael算法，2002年成为标准。它是用来代替原来的DES加密方法的。它也是一个可逆的对称加密算法。

RSA---顶顶有名的非对称公钥加密算法, RSA的安全性依赖于大数的因子分解，但是并没有理论上可以证明破译RSA的难度与大数分解难度是同样的。它是第一个既能用于数据加密也能用于数字签名的算法，也是可逆算法。不过，在不告诉你密钥的情况下，你就是想什么办法加密后的数据也还原不回去，银行系统用它自有道理呵。告诉你个小秘密，前面说过的RC6好像就是有RSA开发组成员参与搞出来的。不过，RSA也有不少缺点。它受到素数产生技术的限制，产生密钥时很麻烦；出于安全性考虑，分组长度至少也要600位以上，运算代价很高、速度比较慢，比DES之类的对称算法要慢的多。它最大的缺点是需要生成大素数及大数取模时可能会产生特别大的数据量，这些都很耗费时间，生成复杂密钥时在单片机上运行可能都不止10分钟，所以解密时还是尽量让PC或服务器来做吧。
MD5---非常著名的哈希算法，不可逆算法
SHA---著名的哈希算法，不可逆算法。也是多用在数字签名上。SHA-1和MD5一样，也被王小云教授找出杂凑冲撞的漏洞，不过也是停留在理论上的。SHA-256是很NB的，它光密钥就有64个long，恐怕想要破解已经是天文数字了。最NB的是SHA-512，咱们这里没有收录，这里恐怕还没有人能用得上。
还有RC6,TEA
前面的章节已经介绍了对称解密算法和非对称加密算法，有很多人疑惑：那我们在实际使用的过程中究竟该使用哪一种比较好呢？
我们应该根据自己的使用特点来确定，由于非对称加密算法的运行速度比对称加密算法的速度慢很多，当我们需要加密大量的数据时，建议采用对称加密算法，提高加解密速度。

对称加密算法不能实现签名，因此签名只能非对称算法。
由于对称加密算法的密钥管理是一个复杂的过程，密钥的管理直接决定着他的安全性，因此当数据量很小时，我们可以考虑采用非对称加密算法。
在实际的操作过程中，我们通常采用的方式是：采用非对称加密算法管理对称算法的密钥，然后用对称加密算法加密数据，这样我们就集成了两类加密算法的优点，既实现了加密速度快的优点，又实现了安全方便管理密钥的优点。
如果在选定了加密算法后，那采用多少位的密钥呢？一般来说，密钥越长，运行的速度就越慢，应该根据的我们实际需要的安全级别来选择，一般来说，RSA建议采用1024位的数字，ECC建议采用160位，AES采用128为即可。



# 总结
[HHT] 剑指Offer
[CCI] Crack the coding interview
## C++方向 chenshuo
•	标准库各容器的基本操作的复杂度。标准库算法的复杂度，例如 std::sort() 的平均复杂度、最坏复杂度（答 O(N^2) 和 O(N log N) 都算对），最坏情况什么时候出现。
•	标准库各容器（deque 除外）的数据结构（标准党勿喷，主流 STL 实现的数据结构都差不多），以及 vector 的容量增长方式。如果回答得特别好，还可以补充问为什么 vector::push_back() 的复杂度是分摊之后的 O(1)，作为加分。
•	出一道使用 lower_bound / upper_bound 能轻松解决的简单算法题；或者实现 set_intersection() 或 set_union() 或 merge()；或者实现 word count，统计每个单词出现的次数（最多十几行代码），如果有时间，输出时再按出现次数排序。
对于社招，补充问：

迭代器失效。（不要求记住所有的场景，但要有这个概念，其实知道数据结构的话不难推理。）
标准库的线程安全性。
自动化对象生命期管理，智能指针，循环引用，weak_ptr。
list 的 insert()/erase() 与 vector 相比哪个快。（这个不是那么简单。）


## 日记
7/30 上午，花了不少时间看linkedin,indeed,jobstreet,花时间太多，jobstreet的好像比较低端。目标可以集中在linkedin,efc,indeed,glassdoor上
7/31 做题,hackerrank,cci, 较难的题建议先看看答案看看思路对不对。考虑做leetcode
工作搜索可以在jobstreet上加入salary,在linkedin/indeed/glassdoor等上使用如下关键字,low latency, developer, stl,c++;搜索工作也要很多时间

考虑加强学习mongodb/nosql, java,Sybase ase?具体计划?

8/31
每天>2题的话感觉脑细胞死得太多，需要混合看书,目前pending的书Effective STL和C++ STL2,more exception c++

学习方向
数据库很关键，银行一般要求oracle,是否考虑考个oracle sql developer? 使用mysql，也要把流程走一遍，比如类型的选择，index, 查询等等。还有就是些数据库的题。

Mongodb好像少一些
http://www.oschina.net/translate/28-mongodb-nosql-database-interview
搭建一个mongodb环境

Oracle的工作也不少,还有hadoop的,KDB 某银行

即时通讯技术和高并发服务器后台技术
Linkedin 的架构,Hadoop,

python
Athena python developer, 但是要求2-4年business experience

目标
这次找工作的体会: 懂JAVA选择面开阔很多,数据库是必须，另外互联网公司相关技能(AWS,hadoop)需要相关经验。Python, scala,haskell 等是点缀.
对于trading firm, C++和算法是关键，要继续刷题.

***
数据库, oracle sql developer认证, MySql
**
c++的并发用户，高性能server,epoll,内核/网卡参数调优，
JAVA, Spring, JEE容器重点是tomcat, WAS ( jboss ), hibernate
*
Python 以及相关framework
Scala/Haskell/F#
Hadoop
AWS
GO/Erlang/其他的互联网架构，技术
angular.js
Hackerrank,codility, leetcode,topcoder等
zeromq,erlang,JMS


## 2021-09
一些思考
要继续提高算法能力,几本书，参与一下周末竞赛，先把algo40看完
cloudnative和aws的能力

JVM和java的方面,optimized java and 高性能，但是还是要写code
多参加面试
2022拿到年终奖之后再考虑

c++如何继续是个问题? 实现vector,hashmap,看看leetcode的专题?还是再另行总结
DBS+PCF 这个路线可能不通
C++的项目?

## 2022/9/8
看着上面的文章有点扯蛋，思考下最近的重点
- payment,openid, trustbank
- aws sa-pro
- c++/lc/interview, uiquant,hrt, millennium?,citadelsec,baml,ms,gic,aws,jpm
- diad 数据密集型app design,system design-alex
另外
kotlin + leetcode 不可行,版本太低，还是坚持c++

GS: website -> x 很多职位关了
GIC: website ->?
BOA: agent yalian -> 9/27
JPM: twr -> x ?
ubiquant: agent suyu -> 9/28
MSFT: mycareers ->?
MS: agent roxy ?
tower: ->
HRT:
nomura: ->
partio: ->?


## payment
https://blog.bytebytego.com/p/payment-system
payment-service <---> outside payment service provider (paypal,stripe,adyen)
fis-opf payment product, 支持fast API

## leetcode 分类精选
array: 763
backtracking: 17
动态规划： 91(decodeways), 198(robber)
图: 207
bfs:964
dfs: 212(TLE)
栈:1944
树:98(验证bst),236
dp:198,322, 1143(最长公共子序列)
并查集:547
数学，位操作: 204(prime), 258(add_digits),260(xor)
综合: 146(lcu)





