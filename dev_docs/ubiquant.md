# 笔试
1. 操作系统一个程序阻塞SIGUSR1 和 SIGCHILD， 当程序变成非阻塞时是否会收到这两个消息
**APUE P233**
>应该可以，而且有队列限制
```
$ ulimit -a | grep sign
pending signals                 (-i) 47913
```

2. thread
第二道是给出五个程序都是实现了用一个线程创建另外两个线程，问这五个里面是否有发生竞态；
fork 出子进程，然后有些waitpid(),考察打印出字符的可能组合
和这个合并到一起:fork 函数的执行流程
child pid =0

3. 如没有名字的类有哪些特点：有没有构造函数和析构函数，是不是编译错误
匿名类，没有ctor/dtor
由于没有为该类提供名称，因此没有分配给它的构造函数，尽管有一个析构函数可用于释放内存块???。

4. a,b,c 在main/foo.c中定义，问运行结果(可能有些是全局，静态函数)
main有:
static int a
int b,c
foo.c里也有int a,b,c问彼此的影响


## 算法*
1. house robber LC198
考了

2. 数独 LC036
考了，就是判断一下而已

3. 两个进程A，B， 其中B依赖A初始化，提供计算数据，如何设计进程间通信，保证数据一致性，完整性，并且A出问题时不影响B


# 准备
## fork执行执行流程

当进程调用fork后控制转入内核，内核将会做4件事儿：
分配新的内存块和内核数据结构给子进程
将父进程部分数据结构内容（数据空间、堆栈等）拷贝到子进程
添加子进程到系统进程列表中
fork返回开始调度器调度


## IO 多路复用
https://juejin.cn/post/6882984260672847879

```
select
它仅仅知道了，有I/O事件发生了，却并不知道是哪那几个流（可能有一个，多个，甚至全部），我们只能无差别轮询所有流，找出能读出数据，或者写入数据的流，对他们进行操作。所以select具有O(n)的无差别轮询复杂度，同时处理的流越多，无差别轮询时间就越长。
1024 个fd

poll本质上和select没有区别，它将用户传入的数组拷贝到内核空间，然后查询每个fd对应的设备状态， 但是它没有最大连接数的限制，原因是它是基于链表来存储的.

epoll可以理解为event poll，不同于忙轮询和无差别轮询，epoll会把哪个流发生了怎样的I/O事件通知我们。所以我们说epoll实际上是**事件驱动（每个事件关联上fd）**的，此时我们对这些流的操作都是有意义的。（复杂度降低到了O(1)）

```

## design
1. 第三道是数组的封装（如数组的底层内存分配有mmap和堆空间创建等方式，因此有不同的数组实现方式，让提出方案把几种实现方式封装），让你写设计方案，感觉好像是写文字就行
https://en.cppreference.com/w/cpp/named_req/Allocator
https://godbolt.org/z/7fnj1rGr9



参考vector
# coding
1. LC091, decodeways
没考到
2. LC11 contain max water
没考到
3. 奇数阶魔方矩阵实现，告诉算法
没考到
```
幻方，就是一个N*N的矩阵中填入1至N^2,使得每行、每列，以及两条对角线上的数之和都相等。当N为奇数时，可用以下的方法来填数。
（1）将1填入第一行的中间；
（2）将数字下一个数填在右上方。
（i)出现越界。若越过第一行，则折返回最后一行。若越过最后一列，则折返回第一列。
（ii）没越界，但右上方已有数了，此时将其填在上一个数的正下方。
（3）对于矩阵的最右上方的格子（第一行最后一列）要特殊处理，因为下一个数同时越过第一行和最后一列，折返时的格子也已经有数了。因此特殊处理，将其填在第二行的最后一列即可。
具体参考程序如下：

#include<stdio.h>
int i,j,n,x,y;
int a[101][101];
int main()
{
 scanf("%d",&n);
 for(i=0;i<=n+1;i++)
 {
  for(j=0;j<=n+1;j++) 
  if(1<=i&&i<=n&&1<=j&&j<=n) a[i][j]=0;   
   else a[i][j]=1;
 }
 x=1;y=n/2+1;
 a[x][y]=1;   //将数字1填在第一行的中间处
 for(i=2;i<=n*n;i++)     //待填数字i  
  {
  if(x==1&&y==n) x=2;   //右上方格子要特殊处理
  else
  {
        x--;y++;        //将数字i填在右上方
        if(x<1) x=n;    //越界判断
        if(y>n) y=1;    //越界判断
     if(a[x][y]>0) {x+=2;y--;}  //填在上一个数的正下方
  }
     a[x][y]=i;   
 }
 for(i=1;i<=n;i++)   //输出幻方阵
 {
  for(j=1;j<n;j++) printf("%d ",a[i][j]);
  printf("%d\n",a[i][n]);
 }
 return 0;
}

```

我的实现
```
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Write C++ code here
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i=0;i<n;i++) {
        for (int j=0; j<n; j++) {
            m[i][j]=0;
        }
    }
    int x=0, y= n/2;
    m[x][y]=1;
    
    for (int i=2;i<=n*n;i++) {
        if (x==0 && y==n-1) {
            x=1;
        } else {
            x--;y++;
            if (x>=0 && y<n) {
                if (m[x][y] > 0) {
                    x+=2;
                    y--;     
                 }
            }
            if (x<0) x=n-1;
            if (y==n) y=0;    
            /*if (m[x][y] > 0) {
                x+=2;
                y--;     
             }*/
        }
        m[x][y] = i;
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

