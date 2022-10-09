# spring/java
https://leetcode.com/discuss/interview-question/1187778/bank-of-america-interview-april-2021-selected

With multi threading handle in system Shutdown. How to handle. Ans:- addShutDownHook
What is threadLocal ?
What is class loader. Types of class loader, can you create your own class loader
Spring app vs springbok app
What is volatile keyword there. I explained including issues with volatile and how atomic can help
How transaction management is done in spring boot
How to create oneToMany relationship in jpa
How to write classes for crud operation. I explained repo, entity and service and how calls are made
Diff between == and equals
What is abstraction. Ways of performing abstraction
When to use interface and when to use abstract class
What is function interface and why it is present
What is predicate function interface in java
with respect to Stream, What is serial and parallel
Best datatype to use for storing say 20 Employees. Only code standpoint, Hashmat otherwise List
What new features are added with Hashmap with java 8
What is hash collision
What do u mean by overriding hashCode implications. I explained him the hashCode method overriding.
How to add 2 source using spring boot
Have you used Build tool ? Maven
What are different maven build goals
What is pom.xml and what is inside it and starter. Explain, I explained dependencies, version, artiufactId and groupId
Rpund 2: Final managerial Round:

Why multiple companies switch. What is the reason?
Define politics.
What do u know about banks
What new technology you have learnt on your own in last few years.
- I spoke about leetcode contribution towards DSA and spring security
We discussed project, learning opportunity and work culture

Features of Java 8
What is Meta-Space?
Can you handle Errors?
What is memory leak?
What is Out-of-Memory-Error? How to resolve it?
Basic Spring Questions


## spring transaction 原理
代理:
cglib,(aop)
JDK实现代理只需要使用newProxyInstance方法

事务的起点是通过 Interceptor 进行拦截的 , 其代理方式也是通过 AOP 实现的 ,其入口类为 CglibAopProxy

transactionmanager=> jpatransactionmanager, 
```
C- DataSourceTransactionManager
C- JdoTransactionManager
C- JpaTransactionManager
C- HibernateTransactionManager
C- JtaTransactionManager
C- OC4JjtaTransactionManager
C- WebSphereUowTransactionManager
C- WebLogicJtaTransactionManager    
```
现阶段看出来的就是通过 SQL 其本身的事务管理来做的 , 不确定是否有其他的环节控制或者通过业务的方式处理 .
也不想细看

## how about kafka?
kafka-client transaction api支持exact once
spring-kafka利用了producer的transaction

## bean 生命周期
componentscan
传统的基于beannamaware beanfactoryaware 接口
beanpost processor, initialize


# Core Java
## hashcode/equal
如果obj1插入后,再改变obj1/field/导致hashcode改变，那么hmap.contains(obj1)是找不到的
即使制造一个obj2其hashcode=原obj1，但是equals!=原obj1，查找也会失败
原因: 造成原hashcode命中不了bucket,但是原object还在bucket对应的存储区域    
## singleton
```
// Java code to create singleton class by
// Eager Initialization
public class GFG
{
// public instance initialized when loading the class
private static final GFG instance = new GFG();

private GFG() {
	// private constructor
}
public static GFG getInstance(){
		return instance;
	}
}
or lazy
public class GFG
{
  // private instance, so that it can be
  // accessed by only by getInstance() method
  private volatile static GFG instance;
 
  private GFG()  {   }
 
  public static GFG getInstance()
  {
    if (instance == null) {
      //synchronized block to remove overhead
      synchronized (GFG.class)  {
        if(instance==null) {
          // if instance is null, initialize
          instance = new GFG();
        }
      }
    }
    return instance;
  }
}

```
## JVM
### class loader 类加载器
, Bootstrap ClassLoader、Extension ClassLoader、AppClassLoader 和URLClassLoader，他们的作用其实从名字就可以大概推测出来了。其中AppClassLoader在很多地方被叫做System ClassLoader 
双亲委派模型=>都是保证object被最顶端的加载器加载
JNDI->线程上下文加载，加载厂商的的jar

### GC
CMS(concurrent mark-sweep), 
G1降低停顿， garbagefirst

# python
list & tuple
heap
partition(seq: list[int])




# 被5或7整除
什么垃圾题
Given n test cases each of which has numbers in form of strings, output all numbers from 1 to that number which is not divisible by 5 or 7.

# 大小写转换
https://www.tutorialride.com/c-strings-program/display-alternate-character-of-string-in-upper-case.htm

# decode ways
lc91?

Let 1 represent ‘A’, 2 represents ‘B’, etc. Given a digit sequence, count the number of possible decodings of the given digit sequence. 

Examples: 

Input:  digits[] = "121"
Output: 3
// The possible decodings are "ABA", "AU", "LA"

Input: digits[] = "1234"
Output: 3
// The possible decodings are "ABCD", "LCD", "AWD"

# prime
lc 204 

# max sum of value
nput: S = “pQrqQPR”
Output: 176
Explanation:
The value of the letter ‘P’ is taken as 25, ‘Q’ is taken as 26, ‘R’ is taken as 24. Now, the sum of values assigned to the characters of the string is 25 + 26 + 24 + 26 + 26 + 25 + 24 = 176, which is maximum among all possible combinations of assigning values.

Input: S = “#aAaa$”
Output: 104

就是看哪个字符重复次数最多，分配给其最大的值
这里0 based, 搞得25对应的是26， 看得很难过
```

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find max possible sum
// of values assigned to each characters
// of the given string
int maxStrength(string s)
{
	// Initialize a frequency array of
	// size 26 with all elements as 0
	vector<int> frequency(26, 0);

	for (char ch : s) {

		// Lowercase character
		if (ch >= 'a' && ch <= 'z') {
			frequency[ch - 'a']++;
		}

		// Uppercase character
		else if (ch >= 'A' && ch <= 'Z') {
			frequency[ch - 'A']++;
		}
	}

	// Sort the frequency array
	sort(frequency.begin(),
		frequency.end());

	// Stores the maximum sum of value
	int ans = 0;

	for (int i = 25; i >= 0; i--) {

		// If the frequency of the
		// current character is > 0
		if (frequency[i] > 0) {
			ans = ans + frequency[i] * (i + 1);
		}

		// Otherwise
		else
			break;
	}

	// Return the maximum sum obtained
	return ans;
}

// Driver Code
int main()
{
	string S = "pQrqQPR";
	cout << maxStrength(S);

	return 0;
}

```


# python
why python is dynamically typed programming
monkey patching=>redirect func=>replace libs in place(runtime)
mutable/immutable data type=>list,set,dict
concatenate 2 tuple
context manager(with xxx.open)
handle exception in python=>try,except,else,finally
dunder methods=>__add__,__multiply__
lambda func=>anonymous
shallow copy, deep copy=>copy.deepcopy()
GIL
namespace, mynamespace/pack1/__init_.py,pack2/__init__.py=>from mynamespace import subpackage_a
@classmethod, fun(cls), @staticmethod,(not access cls state)
middle,django?
numpy, pandas ?
pyspark
SQL

==
a=5;fun():global a,a=xxx
yield
generator
decorator
__iter__
继承 class A(B)