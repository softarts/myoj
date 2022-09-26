
# 图
lc310 一个变种，实则是一个tree，构造一个queue，BFS 把所有叶结点加进去,直到最后只剩下2个点
LC399 给出a/b=2,e/f=3,b/e=4，求a/e
解题，构造一个图
LC133 clone graph克隆一个图



## 介绍
分为有向图，完全无向图，有向完全图，带权重的称为网.
使用邻接矩阵来保存(一个matrix,保存相互两个点之间有无连接), 那必然有很多cell是没有值的(无连接)	
邻接表则比较省空间。每个点的所有连接边用一个链表串起来。
```
/* 邻接表
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
```

广度优先BFS, 深度优先DFS

```
void DFS(int i)
{
  int j;
  visited[i] = true;
  cout << vexs[i] << ' '; /* 打印顶点，也可以其它操作 */
  for (j = 0; j < m_numNodes; j++)
    if (arc[i][j] > 1 && !visited[j])
      DFS(j);/* 对未访问的邻接顶点递归调用 */
}
```

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse()
{
  int i;
  for (i = 0; i < m_numNodes; i++)
    visited[i] = false;/* 初始所有顶点状态都是未访问过状态 */
  for (i = 0; i < m_numNodes; i++)
    if (!visited[i])
      DFS(i);/* 对未访问过的顶点调用DFS，若是连通图,只会执行一次*/
}

# backtrace
// backtrace的套路， 1. exit cond; 2 当前的loop,注意loop的次数依赖于输入
lc17, 电话键盘的字母组合
lc22, 生成括号的组合
LC51,52 N-Queen, 使用一个dfs来判断每个试图摆放的位置是否有效



# sliding window及其变种
LC84,85 计算最大矩形,用一个deque或者stack来保存每个位置的元素
LC239， 需要维护window的上升趋势

# string
lc241 对字符表达式添加括号，计算各种可能的结果，使用分治法，把运算符两侧的表达式递归处理!!

# tree
主要还是递归，分治，和queue迭代的方式
lc94 easy，用循环的方式中序遍历-> 先把所有left压进stack里，再处理每一个pop出的node的right的所有left
lc95 给出n个节点，求所有可能的bst组合，参考241分治法 
lc111 求mindepth,这个无法从dfs中返回depth,直接用一个成员变量来记录mindepth
lc124(amazon h) 也是递归/backtrace中来确定最大值，需要注意的是返回值只能是一条边
lc508, 计算subtree sum，就是node+left+right递归调用
lc515 layer 遍历的一个变种？(102,103)
lc235 最小公共节点,由于是bst,所以可以返回当前，左，右子树


##	二叉树
http://blog.jobbole.com/79305/
二叉查找树的特征,左树的最大值<父节点<右树的最小值
在bst上的操作时间和树的高度成正比，对于含n个节点的完全二叉树，遍历O(N),查找，最坏情况是O(logN)?

二叉查找树要求左节点的值<根节点<右子树的值

前序遍历 - 先根节点,再左节点,，最后右节点
中序遍历- 先左节点，然后根节点，再右节点
后序遍历 - 先左节点，再右节点，最后根节点

LC236 lca，参考hht 50，树的最小公共节点


###	重建二叉树
[HHT] 剑指Offer p72 ,微软编程之美
题目：
给定二叉树的前序队列和中序队列，构建出此二叉树。
比如
前序：
a b d c e f
后序：
d b a e c f

解答:bintree,较难
思路:
前序 -> root|左节点|右节点
中序->左节点|root|右节点
递归，最后简化为如上模式，找出左右节点的起始，长度，递归调用。


### 插入二叉搜索树
```
node * insert(node * root, int value)
{
    node *x = root;
    node *y = nullptr;
    node *z = new node();
    z->data = value;
    while (x != nullptr) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    if (y != nullptr) {
        if (z->data < y->data)
            y->left = z;
        else
            y->right = z;
        return root;
    }
    else {
        return z;
    }
}
```

**LC450 delete node in bst(binary search tree)**
算法导论上的比较复杂，判断待删除node是否有left,right或者同时有，同时有的话需要查找右子树中一个最小值，把最小值的节点来替换待删除节点。然后要重新安排该最小值节点与父节点的关系。
利用递归的做法十分巧妙，直接修改待删除节点,替换val为新的val，然后递归删除最小值节点。

# array
循环，左到右，右到左循环，二分查找，分治，递归
lc33,lc153 rotated array(bytedance), 边界条件很讨厌,先把数组分成left/right rotated
lc53 max subarray, O(N),dp的做法，比较当前的cursum+num[i]和num[i]
lc56 合并interval，就是简单的loop,比较每一个interval决定如何合并
lc121 买卖股票最佳时机，实则有点像DP
lc123 left->right then right->left, 选最大值，其实有点像DP
lc162, findpeak

## two pointer
属于变种？
lc001 two sum (其实hashmap的做法是遍历)
lc15
lc16
lc443，将array转换为char+count


# dynamic programming 
LC055 jump game, 给出一串数组，每个元素的值表明至多能跳几步，求是否有可能到达数组的终点
一开始使用递归解决，然而TLE,后来思考DP，实质上发现有个trick,只要能够判断是否能拓展元素所能到达的最大范围，在循环结束时判断最大范围是否到达尾部即可。
lc121 buy&sell stock,实际只要记住每一个位置的minval
lc174 类似maze题，只能向右向下

lc332, 求数组中能否得到一个组合,和=target，且需要的数组元素数量最小->最小有点DP的味道，但是如何组合->


# 并查集
goldman sachs 给出immediate parent，找出smallest root



# 排序
## partition
分区
陷阱很多:high是size还是至最后一个元素，区间必须包括倒数第二个元素。
比较必须是<=,toexg必须+1

取最后一个元素作为pivot, 从区间low开始比较,记下当前位置和toexg位置，如果当前位置<=pivot,那么交换当前位置和toexg位置,toexg位置+=1，全部结束后再交换pivot位置和toexg位置，返回toexg位置
调用:先进行分区，返回中间点，再分别调用低区和高区

```
int partition(int arr[],int low,int high) {
	/*std::cout << "Before quicksort:\n";	
	for (int i = low; i <= high; i++) {
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;
	std::cout << "After quicksort:\n";*/
	int pivot = arr[high]; // 取最后一个位置pivot
	int toexg = low;  // 第一个作为欲交换的元素
	for (int j = low; j < (high ); j++) {
		if (arr[j] <= pivot) {
			std::swap(arr[toexg], arr[j]);
			toexg += 1;
		}
	}
	std::swap(arr[toexg], arr[high]); // 最后交换pivot和待交换的元素
	/*for (int i = low; i <= high; i++) {
		std::cout << arr[i] << ",";
	}
	std::cout << std::endl;*/
	return toexg;
}
## Quicksort

/*
先进行分区，返回中间点，再分别调用低区和高区
*/
void qsort1(int arr[],int low,int high) {
	if (low < high) {
		int mid = partition(arr, low, high);
		qsort1(arr, low, mid - 1);
		qsort1(arr, mid + 1, high);
	}
}
```

快速排序：平均时间复杂度log2(n)*n，所有内部排序方法中最高好的，大多数情况下总是最好的
最坏情况就是每次都划分n-1和1两个区间，实则等于冒泡排序O(N^2)
最好情况平均划分，为O(N*LogN)

 
神奇之处在于它是稳定的，元素的相对位置都没有变化。
->选择最后一个元素pivot, 然后除开pivot元素进行循环,to_exg初始值为第一个，对于循环中每一个元素，判断ar[idx] <=pivot就递增to_exg以及swap ar[idx]和ar[to_exg]


如果选择第一个元素为pivot? 
另一个分区算法,不是inplace，应该是STL partiton的实现，这个只是把元素分为两部分，放到pivot前后
```
int mypartition(vector<int>&arr, int low, int high)
{
    int pivot = arr[low];//选第一个元素作为枢纽元
    while(low < high)
    {
        while(low < high && arr[high] >= pivot)high--;
        arr[low] = arr[high];//从后面开始找到第一个小于pivot的元素，放到low位置
        while(low < high && arr[low] <= pivot)low++;
        arr[high] = arr[low];//从前面开始找到第一个大于pivot的元素，放到high位置
    }
    arr[low] = pivot;//最后枢纽元放到low的位置
    return low;
}
```




# 数学
lc149  直线上的点，简化成gcd后，直接存到hashmap里
lc1071 gcd of string

# 排序的复杂度

|Heapsort|Quicksort |Insertsort  |Mergesort  |  BinaryTreesort |selectionsort|
|-----------|-----------|-----------|-----------|-----------|---------------|
|N*LogN|N*LogN            |N^2            |N*LogN|N*LogN|N^2
|不稳定|不稳定            |稳定            |稳定||




假定在待排序的记录序列中，存在多个具有相同的关键字的记录，若经过排序，这些记录的相对次序保持不变，即在原序列中，ri=rj，且ri在rj之前，而在排序后的序列中，ri仍在rj之前，则称这种排序算法是稳定的；否则称为不稳定的。

# 优先队列的实现 TODO
jumptrading



##	数组


LC189环形数组的移位
数组右移1位，a[i] = a[i-1], 数组长度为N,右移k位，(i=i-k)<0的话,i+N正好环形指向其另一端. 


###	二维数组旋转
int loop = n / 2;
int start = 0;
int end = n;

for (int j = 0; j < loop; j++) {        
    for (int i = start; i < end-1; i++) {
        int offset = i - start;
        // save top
        int top = m[start][i];
        // left->top
        m[start][i] = m[end - offset - 1][start];
        // bottom -> left
        m[end - offset - 1][start] = m[end - 1][end - offset - 1];
        // right - > bottom
        m[end - 1][end - offset - 1] = m[i][end - 1];
        // top -> right
        m[i][end - 1] = top;
    }        
    //printMatrix((int*)m, n);
    //cout << "\n";
    start++; end--;
}

rotate_matrix_1_6.cpp
思路就是逐个交换，left->top,bottom->left,要注意offset,循环的范围比正方形少一个元素。


###	二位数组的查找tbd

从数组中取出所有可能的子字符串(不包括字符串本身)
未知来源, 很多题需要这样做，可以用两个loop来做：第一个loop是取得长度，第二个loop是起始位置
  for (int len = 1; len < size; len++) { // allow sub str only, not the whole string
            for (int pos = 0; pos <= size - len; pos++) {
                string sub = str.substr(pos, len);
                sort(sub.begin(), sub.end());
                ma[sub]++;
            }
        }


def lcp(string):
    ret = {}
    for i in range (1, len(string)):
        for pos in range(0, len(string) - i +1):
            sub = string[pos:pos+i]
            if sub in ret:
                ret[sub] += 1
            else:
                ret[sub] = 0
    return ret

next_permutation
实现

###	全排列
HHT 028 使用递归的思路
```
Func(string, step)
当step = len(string)时打印
For loop = step to len(string); step起始值=0,
String_copy = current string
Func(string_copy,step+1),step+1 即取子字符串
```

next_permutation实现
https://blog.csdn.net/lsaejn/article/details/79735824
很巧妙
```
template<class BidirIt>
bool next_permutation(BidirIt first, BidirIt last)
{
    if (first == last) return false;//空的数组
    BidirIt i = last;
    if (first == --i) return false;//只有一个元素
 
    while (true) {
        BidirIt i1, i2;
 
        i1 = i;//让i1指向尾部，i作为游标向前走
        if (*--i < *i1) {//从后往前看，如果是升序，进入下一循环（需要先检查是不是到头）
            i2 = last;//进入循环，也就是说明找到了降序值，例子里的2<7。现在i就是2的iter
            while (!(*i < *--i2))//从后向前找到第一个大于2的数
                ;
            std::iter_swap(i, i2);//交换。即2，3
            std::reverse(i1, last);//再逆序
            return true;
        }
        if (i == first) {
            std::reverse(first, last);
            return false;
        }
    }
}
```

### 移位数组
即使移位了还是可以采用分治，二分法
033 search in rotated arry 有序的数组可能在某处发生rotated，变成4,5,6,7,0,1,2这种形式，给出一个target，查找出它在这个数组里的位置。要求算法复杂度好于O(N)

081 search in rotated array2，有序的数组可能在某处发生rotated,查找target是否存在. 采用二分法的时候需要判断边界条件。如果某一侧有序并且target落在这个区间，则容易判断。如果left==mid，则只能递增left

##	字符串
LC005 Longest Palindromic Substring 

去除重复字符
Design an algorithm and write code to remove the duplicate characters in a string 
without using any additional buffer NOTE: One or two additional variables are fine 
An extra copy of the array is not  FOLLOW UP

Write the test cases for this method
->sort and remove->O(NLogN)->O(N)
->允许的话，使用array to keep result
->不允许额外的buffer,in-place使用字符串所在的buffer,先把第一个字母放入buffer(这个肯定不是重复字符)，接着从i=1开始扫描，和buffer中的每一个进行比较，发现buffer中没有的就放入buffer,O(N^2)
Uniquechar.cpp

CCI (cracking code interview?) 
反转字符串
Write code to reverse a C-Style String (C-String means that “abcd” is represented as five characters, including the null character )
反转C-style字符串(cct)
[cct] p96 做法和书本基本一样，可能书的某些写法更简洁
*str++ = *end;
*end-- = tmp;

利用字符串乘法
```
string multiply(string &num1, string num2) {
    string res;
    int a, b, c, m, n, l, k, sum, carry;
    char d;

    m = num1.size() - 1;
    n = num2.size() - 1;
    carry = 0;
    for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
            l = res.size() - 1;
            a = num1[i] - '0';
            b = num2[j] - '0';
            k = (m-i) + (n-j);

            if (l >= k) c = res[l-k] - '0';
            else c = 0;

            sum = a * b + c + carry;
            carry = sum / 10;
            d = char(sum % 10 + '0');

            if (l >= k) res[l-k] = d;
            else res.insert(0, &d, 1);

            if (j == 0 && carry) {
                d = char(carry + '0');
                res.insert(0, &d, 1);
                carry = 0;
            }
        }
    }

    return res[0] == '0' ? "0" : res;
}
```

数组/字符串
KMP搜索




替换空格
[hht] p61
O(N^2)从首部开始替换，会造成多次替换
O(N)分配足够空间后，从尾部开始
问题，两种场景
1.创建新的字符串，可以直接扫描和copy;
2.使用原有字符串，只能移动字符



寻找变形字符串
http://www.geeksforgeeks.org/anagram-substring-search-search-permutations/

生成全排列

使用set来保存排列结果，因为无法区分重复字符是不是属于一种不同的排列，需要看看next_permutation的实现
For loop中需要一个临时copy,因为1234->1324之后，递归处理324的字串24排列了，还需要保存原有的字符去继续处理234的子串34的排列
void permutation(std::string &s, int step, set<string> &ss)
{    
    if (step == s.length())
    {
        //std::cout << s << std::endl;
        ss.insert(s);
    }
    else
    {
        for (int i = step; i < s.length(); i++)
        {
            std::string temps = s;
            std::string::value_type ch = temps[i];
            temps[i] = temps[step];
            temps[step] = ch;
            permutation(temps, step + 1, ss);
        }
    }    
}

python的实现类同:

def permutations(string, step = 0):

    # if we've gotten to the end, print the permutation
    if step == len(string):
        print "".join(string)  # how to exit recursive!!!

    # everything to the right of step has not been swapped yet
    for i in range(step, len(string)):

        # copy the string (store as array)
        string_copy = [character for character in string]

        # swap the current index with the step
        string_copy[step], string_copy[i] = string_copy[i], string_copy[step]

        # recurse on the portion of the string that has not been swapped yet (now it's index will begin with step + 1)
        permutations(string_copy, step + 1)

使用next_permutation实现
int solution(int N)
{
	std::string s = std::to_string(N);
    std::sort(s.begin(), s.end());
    int count = 1;
    while (next_permutation(s.begin(),s.end()))
    {
        count++;
    }
    return count;
}

TODO: next_permutation的实现





##	动态规划
使用动态规划的场合，一个问题的最优解包括其子问题的最优解，我们就称此问题具有最优子结构(也可能是适用贪心算法)，通常自底向上求解。原问题的最优解=子问题的最优解+本次选择的代价
一般是O(N^2)的复杂度,leetcode多数题目限定table size，例如可以直接bool table[1000][1000]={false};
DP的基本套路，使用一个数组来记住之前的状态
https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems


https://www.topcoder.com/community/data-science/data-science-tutorials/dynamic-programming-from-novice-to-advanced/
A DP is an algorithmic technique which is usually based on a recurrent formula and one (or some) starting states. A sub-solution of the problem is constructed from previously found ones. DP solutions have a polynomial complexity which assures a much faster running time than other techniques like backtracking, brute-force etc.  （start state or recurrent formula）
主要问题在于什么场合下需要使用DP

###	最长公共子串
Hht-20
算法导论p238

### [hht-31]连续子数组的最大值(p188)
当前最优解=上一个最优解+本元素；或者等于max(本元素,前一个解<0)
```
int findmaxsub(vector<int> &arr, int &arg) {  
    int n = arr.size();
    int sum = 0;
    int big = ~0;
    int ncsum = 0;
    for (int i = 0; i < n; i++) {
        if (sum < 0) {
            sum = arr[i];
        }
        else {
            sum += arr[i];            
        }
        if (arr[i] > 0) {
            ncsum += arr[i];
        }
        big = max(sum, big);
    }
    if (big == ~0) {  // 当都是负数的时候返回第一个元素
        big = arr[0];
        arg = arr[0];
    }
    else {
        arg = ncsum;
    }        
    return big;
}
```

### 找出最长的递增序列的长度 TODO
leetcode
 https://leetcode.com/problems/longest-increasing-subsequence/description/

[10, 9, 2, 5, 3, 7, 101, 18] -> [2,3,7,101] (4)， 也可以是[2,5,7,101] (4)
思路：

构造子问题和本次选择的代价
dp[n],新增元素a[i]和已遍历的序列B，假如B中存在一个元素b[j]小于a[i],那么记下dp[i]++,然后再与dp[j]比较，取两者最大值，与dp[j]的递归比较很重要，这意味着吸收前一个状态的结果。是DP的重点。


http://blog.csdn.net/u013445530/article/details/45645307
无法理解d(i)=min{ d(i-vj)+1 }，其中i-vj >=0，vj表示第j个硬币的面值;
Ok

**LC062**
 unique path 给出一个棋盘，只允许右移或者下移，计算共有多少种走法到达右下角。可以用递归(TLE)，
也可以用dp，构造一个状态，它的走法等于它往右走和往下走的走法总和。起始状态为[m-1][n-1]，然后逐步倒退到[1][1]

**LC070**
 climbing stair 递归，类似的转移状态，可以从f(n-1)跳一级，也可以从f(n-2)跳2级，所以f(n)=f(n-1)+f(n-2)

**LC091**
 decode ways和斐波那契的思路很像，套路就是利用像递归的思路那样形成转移状态:i未知的decode组合等于自己独立或者与前一个数结合的decode的个数的总和。后面的每一位数都可以这样递归操作: tmp = dp2, dp2=dp1+dp2, dp1=tmp

**LC198**
抢劫房子，每个房子的价值不同，不能选择相连的房子，如何能选出价值总和最大的房子。


813 一串数组,9,1,2,3,9, k=3分为三组，求出每组的平均值的和的最大值是多少,例如，这样分的时候:9/1,2,3/9 得到最大值20 (=9+2+9)
dp 的思路
double largestSumOfAverages(vector<int>& A, int K) {
        if(A.empty()) return 0.0;

        int n = A.size();
        vector<double> dp(n, 0);
        double sum = 0;
        for(int i=n-1;i>=0;i--){
            sum += A[i];
            dp[i] = sum / (n-i);
        }
        double ans = dp[0];
        for(int k=1;k<K;k++){
            //vector<double> next(n, INT_MIN);
            for(int i=0;i<n-k;i++){
                double s2 = A[i];
                dp[i] = s2 + dp[i+1];
                for(int j=i+1;j<n-k;j++){
                    s2 += A[j];
                    dp[i] = max(dp[i], 1.0 * s2/(j-i+1) + dp[j+1]);
                }
            }

            ans = max(ans, dp[0]);
        }

        return ans;
    }
算法设计的很精巧,最优解转化为子问题的最优解.
状态转换公式：
初始阶段： 声明数组dp[n], dp[i]=数组i~n-1的累计和，此时得到分组数m=1，组内元素个数=n，average=数组的累计和/元素个数。
开始遍历数组，将dp更新为m+1分组时候所能取到的averagesum最大值。 dp[j] = max(dp[j], sum[j~x]+dp[x]),
继续更新dp,直到m=k.
根据这个思路改写的代码：
double largestSumOfAverages(vector<int>& A, int K) {
        if (A.empty())
            return 0;
        size_t n =A.size();
        vector<double> dp(n,0);
        double s = 0;
        for (int i=n-1;i>=0;i--) {
            s+=A[i];
            dp[i]=s/(n-i);
        }
        for (int m=1;m<K;m++) {  // 1~k
            for (int i=0;i<n-m;i++) {
                double ksum = 0;
                for (int j=i;j<n-m;j++) {
                    ksum+=A[j];
                    double g = dp[j+1]+1.0*ksum/(j+1-i);
                    dp[i] = max(dp[i], g);
                }
            }
        }

        return dp[0];
    }

解题思路： 问题的解= 子状态(k-1) 解与当前的组合所形成的（k个分组）中的最优解

另一个思路：



我用递归的思路：
double largestSumOfAverages0(vector<int>& A, int K) {
        double maxsum = 0.0, prev = 0.0;
        if (K>A.size())
            return 0.0;
        return next(A, K, 0, prev, maxsum);
    }

    double next(vector<int>& nums, int k, int start, double &prev, double &maxsum) {
        int remain = nums.size() - start;
        if (k == 1) {
            return prev+accumulate(nums.begin()+start, nums.end(), 0.0)/(remain);
        }
        double sum;
        for (int i=0;i< remain-k+1; i++) {
            sum = prev + accumulate(nums.begin()+start, nums.begin()+start+i+1, 0.0)/(i+1);
            maxsum = max(maxsum, next(nums,k-1,start+i+1, sum, maxsum));
        }
        return maxsum;
    }




**算法导论-切割钢条的最优解**
转化为求解形式一样，但规模小的子问题，通常是递归形式，例如，第一次分割为i和(n-i)，然后n-i部分继续切割，把每次结果存下来。

12.7.2	最大sum(连续和不连续)
不连续，只需把所有正数加起来即可
连续的，

**背包问题**
http://love-oriented.com/pack/P01.html



## Linked list
148  O(1) 的空间来对链表排序, 链表的排序参考STL中的sort(使用merge来实现),思路是把链表分成2段，然后采用分治法对两段逐步排序，合并。

HHT11
从尾到头打印链表
[HHT] p68 使用stack,可以保存已走过的链表
或者递归，实现更加简练,但要注意栈溢出

160， 两个链表的交差点

12.3	two pointer TODO

2.1 Write code to remove duplicates from an unsorted linked list
How would you solve this problem if a temporary buffer is not allowed?
->single/double? TBD 实现类似删除重复字符

2.2 Implement an algorithm to find the nth to last element of a singly linked list
->意思是找出倒数第n个节点(nth to last),算法就是取得p1,p2两个指针，令其distance=n,然后判断p2->next是否为null

static struct ListNode* findnth(struct ListNode *head, int n) {	
	if ((head == nullptr) || n < 0)
		return nullptr;
	struct ListNode *p1 = head;
	struct ListNode *p2 = head;
	for (int i = 0; i < n-1;i++) {
		if (p2 == nullptr)
			return nullptr;
		p2 = p2->m_pNext;
	}

	while (p2->m_pNext!=nullptr) {
		p2 = p2->m_pNext;
		p1 = p1->m_pNext;
	}
	return p1;
}


2.3Implement an algorithm to delete a node in the middle of a single linked list, given 
only access to that node
EXAMPLE
Input: the node ‘c’ from the linked list a->b->c->d->e
Result: nothing is returned, but the new linked list looks like a->b->d->e
普通的链表删除，但和题目理解有些差别。

##	greedy
贪心法，又称贪心算法、贪婪算法、或称贪婪法，是一种在每一步选择中都采取在当前状态下最好或最优（即最有利）的选择，从而希望导致结果是最好或最优的算法。比如在旅行推销员问题中，如果旅行员每次都选择最近的城市，那这就是一种贪心算法。 

贪心算法在有最优子结构的问题中尤为有效。最优子结构的意思是局部最优解能决定全局最优解。简单地说，问题能够分解成子问题来解决，子问题的最优解能递推到最终问题的最优解。

贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。


## backtracking
回溯算法实际上一个类似枚举的搜索尝试过程，主要是在搜索尝试过程中寻找问题的解，当发现已不满足求解条件时，就“回溯”返回，尝试别的路径,
对于回溯问题，总结出一个递归函数模板，包括以下三点,
1.	递归函数的开头写好跳出条件，满足条件才将当前结果加入总结果中
2.	已经拿过的数不再拿 if(s.contains(num)){continue;}
3.	遍历过当前节点后，为了回溯到上一步，要去掉已经加入到结果list中的当前节点。

这种题目都是使用这个套路，就是用一个循环去枚举当前所有情况，然后把元素加入，递归，再把元素移除
按照这个套路来做，可以解决backTracking的问题

0078 subset
list.add(nums[i]); // 第三步 元素加入临时集合            
backTracking(res, list, nums, i + 1); // 第四步 回溯
list.remove(list.size() - 1); // 第五步 元素从临时集合移除

对于subset有一种组合的套路
//    这种方法是一种组合的方式//
//    1.最外层循环逐一从 nums 数组中取出每个元素 num
//    2.内层循环从原来的结果集中取出每个中间结果集，并向每个中间结果集中添加该 num 元素




12.8	递归，组合
这个常常放在一起。很多组合问题都是用递归来解决
022 生成（）对，思路是left 左括号未到达n的时候可以一直加，达到后开始加right括号，退出条件是直到两者相等。注意保存结果的变量使用copy,这样在child stack里修改的结果不影响到parent stack.
另外注意递归前push的递归后一般要pop



## Binary search
以leetcode 035为例, start=0, end为最后一个元素，所以退出条件为start<=end,由于是<=end,所以缩小区间方法为mid+-1，避开已经判断过的mid本身
int start=0,end=nums.size()-1,mid;
        while (start<=end) {
            mid = (end+start)/2;
            if (nums[mid]>target) {
                end = mid-1;
            } else if (nums[mid] < target) {
                start = mid+1;
            } else {
                return mid;
            }
        }
        return target>nums[mid]?mid+1:mid;
可能还有另外一种二分法
Start<end,-> end=mid,
int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }



## 位操作 bit TODO
lc260 值的一看， 两个常见套路

https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary:-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

```
Wiki
Bit manipulation is the act of algorithmically manipulating bits or other pieces of data shorter than a word. Computer programming tasks that require bit manipulation include low-level device control, error detection and correction algorithms, data compression, encryption algorithms, and optimization. For most other tasks, modern programming languages allow the programmer to work directly with abstractions instead of bits that represent those abstractions. Source code that does bit manipulation makes use of the bitwise operations: AND, OR, XOR, NOT, and bit shifts.

Bit manipulation, in some cases, can obviate or reduce the need to loop over a data structure and can give many-fold speed ups, as bit manipulations are processed in parallel, but the code can become more difficult to write and maintain.

Details
Basics
At the heart of bit manipulation are the bit-wise operators & (and), | (or), ~ (not) and ^ (exclusive-or, xor) and shift operators a << b and a >> b.

There is no boolean operator counterpart to bitwise exclusive-or, but there is a simple explanation. The exclusive-or operation takes two inputs and returns a 1 if either one or the other of the inputs is a 1, but not if both are. That is, if both inputs are 1 or both inputs are 0, it returns 0. Bitwise exclusive-or, with the operator of a caret, ^, performs the exclusive-or operation on each pair of bits. Exclusive-or is commonly abbreviated XOR.

Set union A | B
Set intersection A & B
Set subtraction A & ~B
Set negation ALL_BITS ^ A or ~A
Set bit A |= 1 << bit
Clear bit A &= ~(1 << bit)
Test bit (A & 1 << bit) != 0
Extract last bit A&-A or A&~(A-1) or x^(x&(x-1))
Remove last bit A&(A-1)
Get all 1-bits ~0
Examples
Count the number of ones in the binary representation of the given number

int count_one(int n) {
    while(n) {
        n = n&(n-1);
        count++;
    }
    return count;
}
Is power of four (actually map-checking, iterative and recursive methods can do the same)

bool isPowerOfFour(int n) {
    return !(n&(n-1)) && (n&0x55555555);
    //check the 1-bit location;
}
^ tricks
Use ^ to remove even exactly same numbers and save the odd, or save the distinct bits and remove the same.

Sum of Two Integers
Use ^ and & to add two integers

int getSum(int a, int b) {
    return b==0? a:getSum(a^b, (a&b)<<1); //be careful about the terminating condition;
}
Missing Number
Given an array containing n distinct numbers taken from 0, 1, 2, …, n, find the one that is missing from the array. For example, Given nums = [0, 1, 3] return 2. (Of course, you can do this by math.)

int missingNumber(vector<int>& nums) {
    int ret = 0;
    for(int i = 0; i < nums.size(); ++i) {
        ret ^= i;
        ret ^= nums[i];
    }
    return ret^=nums.size();
}
| tricks
Keep as many 1-bits as possible

Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.

long largest_power(long N) {
    //changing all right side bits to 1.
    N = N | (N>>1);
    N = N | (N>>2);
    N = N | (N>>4);
    N = N | (N>>8);
    N = N | (N>>16);
    return (N+1)>>1;
}
Reverse Bits
Reverse bits of a given 32 bits unsigned integer.

Solution
uint32_t reverseBits(uint32_t n) {
    unsigned int mask = 1<<31, res = 0;
    for(int i = 0; i < 32; ++i) {
        if(n & 1) res |= mask;
        mask >>= 1;
        n >>= 1;
    }
    return res;
}
uint32_t reverseBits(uint32_t n) {
	uint32_t mask = 1, ret = 0;
	for(int i = 0; i < 32; ++i){
		ret <<= 1;
		if(mask & n) ret |= 1;
		mask <<= 1;
	}
	return ret;
}
& tricks
Just selecting certain bits

Reversing the bits in integer

x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);
Bitwise AND of Numbers Range
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive. For example, given the range [5, 7], you should return 4.

Solution
int rangeBitwiseAnd(int m, int n) {
    int a = 0;
    while(m != n) {
        m >>= 1;
        n >>= 1;
        a++;
    }
    return m<<a; 
}
Number of 1 Bits
Write a function that takes an unsigned integer and returns the number of ’1’ bits it has (also known as the Hamming weight).

Solution
int hammingWeight(uint32_t n) {
	int count = 0;
	while(n) {
		n = n&(n-1);
		count++;
	}
	return count;
}
int hammingWeight(uint32_t n) {
    ulong mask = 1;
    int count = 0;
    for(int i = 0; i < 32; ++i){ //31 will not do, delicate;
        if(mask & n) count++;
        mask <<= 1;
    }
    return count;
}
Application
Repeated DNA Sequences
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: “ACGAATTCCG”. When studying DNA, it is sometimes useful to identify repeated sequences within the DNA. Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
For example,
Given s = “AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT”,
Return: [“AAAAACCCCC”, “CCCCCAAAAA”].

Solution
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int sLen = s.length();
        vector<string> v;
        if(sLen < 11) return v;
        char keyMap[1<<21]{0};
        int hashKey = 0;
        for(int i = 0; i < 9; ++i) hashKey = (hashKey<<2) | (s[i]-'A'+1)%5;
        for(int i = 9; i < sLen; ++i) {
            if(keyMap[hashKey = ((hashKey<<2)|(s[i]-'A'+1)%5)&0xfffff]++ == 1)
                v.push_back(s.substr(i-9, 10));
        }
        return v;
    }
};
But the above solution can be invalid when repeated sequence appears too many times, in which case we should use unordered_map<int, int> keyMap to replace char keyMap[1<<21]{0}here.

Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times. (bit-counting as a usual way, but here we actually also can adopt sorting and Moore Voting Algorithm)

Solution
int majorityElement(vector<int>& nums) {
    int len = sizeof(int)*8, size = nums.size();
    int count = 0, mask = 1, ret = 0;
    for(int i = 0; i < len; ++i) {
        count = 0;
        for(int j = 0; j < size; ++j)
            if(mask & nums[j]) count++;
        if(count > size/2) ret |= mask;
        mask <<= 1;
    }
    return ret;
}
Single Number III
Given an array of integers, every element appears three times except for one. Find that single one. (Still this type can be solved by bit-counting easily.) But we are going to solve it by digital logic design

Solution
//inspired by logical circuit design and boolean algebra;
//counter - unit of 3;
//current   incoming  next
//a b            c    a b
//0 0            0    0 0
//0 1            0    0 1
//1 0            0    1 0
//0 0            1    0 1
//0 1            1    1 0
//1 0            1    0 0
//a = a&~b&~c + ~a&b&c;
//b = ~a&b&~c + ~a&~b&c;
//return a|b since the single number can appear once or twice;
int singleNumber(vector<int>& nums) {
    int t = 0, a = 0, b = 0;
    for(int i = 0; i < nums.size(); ++i) {
        t = (a&~b&~nums[i]) | (~a&b&nums[i]);
        b = (~a&b&~nums[i]) | (~a&~b&nums[i]);
        a = t;
    }
    return a | b;
}
;
Maximum Product of Word Lengths
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given [“abcw”, “baz”, “foo”, “bar”, “xtfn”, “abcdef”]
Return 16
The two words can be “abcw”, “xtfn”.

Example 2:
Given [“a”, “ab”, “abc”, “d”, “cd”, “bcd”, “abcd”]
Return 4
The two words can be “ab”, “cd”.

Example 3:
Given [“a”, “aa”, “aaa”, “aaaa”]
Return 0
No such pair of words.

Solution
Since we are going to use the length of the word very frequently and we are to compare the letters of two words checking whether they have some letters in common:

using an array of int to pre-store the length of each word reducing the frequently measuring process;
since int has 4 bytes, a 32-bit type, and there are only 26 different letters, so we can just use one bit to indicate the existence of the letter in a word.
int maxProduct(vector<string>& words) {
    vector<int> mask(words.size());
    vector<int> lens(words.size());
    for(int i = 0; i < words.size(); ++i) lens[i] = words[i].length();
    int result = 0;
    for (int i=0; i<words.size(); ++i) {
        for (char c : words[i])
            mask[i] |= 1 << (c - 'a');
        for (int j=0; j<i; ++j)
            if (!(mask[i] & mask[j]))
                result = max(result, lens[i]*lens[j]);
    }
    return result;
}
Attention
result after shifting left(or right) too much is undefined
right shifting operations on negative values are undefined
right operand in shifting should be non-negative, otherwise the result is undefined
The & and | operators have lower precedence than comparison operators
Sets
All the subsets
A big advantage of bit manipulation is that it is trivial to iterate over all the subsets of an N-element set: every N-bit value represents some subset. Even better, if A is a subset of B then the number representing A is less than that representing B, which is convenient for some dynamic programming solutions.

It is also possible to iterate over all the subsets of a particular subset (represented by a bit pattern), provided that you don’t mind visiting them in reverse order (if this is problematic, put them in a list as they’re generated, then walk the list backwards). The trick is similar to that for finding the lowest bit in a number. If we subtract 1 from a subset, then the lowest set element is cleared, and every lower element is set. However, we only want to set those lower elements that are in the superset. So the iteration step is just i = (i - 1) & superset.

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> vv;
    int size = nums.size(); 
    if(size == 0) return vv;
    int num = 1 << size;
    vv.resize(num);
    for(int i = 0; i < num; ++i) {
        for(int j = 0; j < size; ++j)
            if((1<<j) & i) vv[i].push_back(nums[j]);   
    }
    return vv;
}
Actually there are two more methods to handle this using recursion and iteration respectively.

Bitset
A bitset stores bits (elements with only two possible values: 0 or 1, true or false, …).
The class emulates an array of bool elements, but optimized for space allocation: generally, each element occupies only one bit (which, on most systems, is eight times less than the smallest elemental type: char).

// bitset::count
#include <iostream>       // std::cout
#include <string>         // std::string
#include <bitset>         // std::bitset

int main () {
  std::bitset<8> foo (std::string("10110011"));
  std::cout << foo << " has ";
  std::cout << foo.count() << " ones and ";
  std::cout << (foo.size()-foo.count()) << " zeros.\n";
  return 0;
}
Always welcom new ideas and practical tricks, just leave them in the comments!
```

**LC268 missing number**
一个数组从0开始，其中缺了一个数字，找出来。

例如 N=5, 0,1,2,3，缺了4
利用bit操作的特点,与自身xor = 0,构造一个检测数组={0,1,2,3,4}, 从0~(N-1)，然后与数组里每个数字xor,最后剩下来的就是缺失的数字.





### nth_element 实现
为何复杂度是O(N)?
```
vector<int> vec = { 0, 1, 2, 4, 6, 5, 3, 5, 4, 8, 11, 34, 77, 45, 33, 42, 65, 89, 90, 65, 37, 35, 3, 1, 4, 6, 8, 42, 68, 66, 42, 22, 6, 9, 98, 97, 94, 25, 27, 29, 101 };
    int nth = (vec.size()-1) / 2;
    int low = 0;
    int high = vec.size() - 1;
    int cut = partition(&vec[0], low, high);
    while (cut!=nth) {        
        if (cut < nth) {
            low = cut + 1;
        }
        else  {
            high = cut - 1;
        } 
        cut = partition(&vec[0], low, high);
    }
cout << vec[nth];
```
利用partition函数，反复对区间数据进行按pivot的划分为两部分，再加以比较nth,逐步缩小区间，直到pivot点正好等于nth
STL的实现更加优化，例如取首中尾部的median，当元素少于一定数量(32)的时候使用insert_sort

### Insert sort 
第一个元素假定已有序，从第二个元素开始比较，[0-当前元素-1]为有序，和key比较的时候，如果比key大的话，需要逐项右移:a[i+1] = a[i]以腾出空间，退出条件是小于key或者已越过最左侧
最优情况，正向有序, O(N)，最坏情况,反序, O(N^2),平均情况是O(N^2)

一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
从第一个元素开始，该元素可以认为已经被排序
取出下一个元素，在已经排序的元素序列中从后向前扫描
如果该元素（已排序）大于新元素，将该元素移到下一位置
重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
将新元素插入到该位置后
重复步骤2~5
如果比较操作的代价比交换操作大的话，可以采用二分查找法来减少比较操作的数目。该算法可以认为是插入排序的一个变种，称为二分查找插入排序。

###	二分查找
实现并不难
```
bool binarySearch(int arr[], int val, int len) {
	if (arr == nullptr || len == 0)
		return;

	int low = 0;
	int high = len - 1;

	while (low <= high) {
		int mid = (high - low) / 2 + low;

		if (val > arr[mid]) {
			low = mid + 1;
		}
		else if (val < arr[mid]) {
			high = mid - 1;
		}
		else {
			return true;
		}
	}
	return false;
}
```

固定模式:关键是每次比较后需要把high = mid-1以及low = mid+1从而跳开已比较的元素, 退出条件是low<=high
复杂度: LogN

**堆排序**
TODO
堆是一个二叉树？只要保证根节点最大，不需要成为一个二叉搜索树
最大化堆
```
void MaxHeapify(int Ary[], int nIndex, int nHeapSize)
{
    int nL = LEFT(nIndex);
    int nR = RIGHT(nIndex);
    int nLargest;

    if (nL <= nHeapSize && Ary[nIndex] < Ary[nL])
    {
        nLargest = nL;
    }
    else
    {
        nLargest = nIndex;
    }

    if (nR <= nHeapSize && Ary[nLargest] < Ary[nR])
    {
        nLargest = nR;
    }

    if (nLargest != nIndex)
    {
        // 调整后可能仍然违反堆性质
        swap(Ary[nLargest], Ary[nIndex]);
        MaxHeapify(Ary, nLargest, nHeapSize);
    }
}
```

最大堆，最小堆
N个元素的序列K1,K2,K3,...,Kn.称为堆，当且仅当该序列满足特性：Ki≤K2i Ki ≤K2i+1(1≤ I≤ [N/2])。
最大堆:除了根节点，所有节点都要满足A[parent(i)]>=A[i]
最小堆。相反
Set,map,红黑树，实现是最大堆?

std::make_heap 是最大堆排序，第一个元素为根节点
pop_heap()用于弹出堆中的第一个元素，并把它放到区间的最后一个位置，然后重新将前面的元素构建成一个堆。
push_head() 用于将指定区间的最后一个元素加入堆中并使整个区间成为一个新的堆。注意前提是最后一个元素除外的所有元素已经构成一个堆。


## 其它

036 valid Sudoku 判断sudoku棋盘是否有效。普通的逻辑操作题，亮点在于对于列操作，不需要专门把列数据拿出来，而是在外部定义了一个二维数组来保存列数据（把列数据转化成了行数据）


使用两个stack实现一个队列(HHT)
[HHT] p76
思路，当pop的时候把stack1 全部pop并push到另一个stack2,正好就是原来的插入顺序。
cqueue_by_stack.cpp


[hht]  p55 有序的二维数组,
解法 选择右上角的数字，逐次缩小范围
全排列
HHT 028 使用递归的思路

Func(string, step)
当step = len(string)时打印
For loop = step to len(string); step起始值=0,
String_copy = current string
Func(string_copy,step+1),step+1 即取子字符串


12	Leetcode
https://github.com/kamyu104/LeetCode/blob/master/C%2B%2B/count-of-smaller-numbers-after-self.cpp

12.1	union find 并查集

## HACKERRANK
20.1	Algorithm
20.1.1	Extra long factorials
https://www.hackerrank.com/challenges/extra-long-factorials
计算阶乘
You are given an integer N. Print the factorial of this number.
N!=N×(N−1)×(N−2)×⋯×3×2×1
Note: Factorials of N>20 can't be stored even in a 64−bit long long variable. Big integers must be used for such calculations. Languages like Java, Python, Ruby etc. can handle big integers but we need to write additional code in C/C++ to handle such large values.
We recommend solving this challenge using BigIntegers.


# TODO

18	CCI (crack code interview)
18.1	数组
Implement an algorithm to determine if a string has all unique characters What if you 
can not use additional data structures?
->No hashtable, use array? Assume ascii[256]
->如果考虑a-z则可以使用bit来保存


Stack/queue
3.1	Describe how you could use a single array to implement three stacks

18.3	Tree/Graph
4.1 Implement a function to check if a tree is balanced For the purposes of this question, 
a balanced tree is defined to be a tree such that no two leaf nodes differ in distance 
from the root by more than one


18.4	C++
Write a method to print the last K lines of an input file using C++




zigzag
原题 https://oj.leetcode.com/problems/zigzag-conversion/

一个解答 http://blog.csdn.net/flyupliu/article/details/21160005
算法是从row0开始逐个打印，计算row0中每一个元素(间隔是w*(nRows-1))，再去计算row1, (间隔是w*(nRows-1)-2*i)
第一排的数字可以确定为0~(nRows-1)，row1的数字1,7,9,15,17,其中7=j+row1*2，找出数字的规律.这个算法比我的简单

我的解答 https://oj.leetcode.com/problems/zigzag-conversion/submissions/



21.	GOOGLE TEST
函数测试 TEST
类测试 TEST_F
http://www.cnblogs.com/bangerlee/archive/2011/10/05/2198532.html
派生一个测试类，然后定义待测试对象，在这个过程中待测试对象的状态会一直有效
class QueueTest : public ::testing::Test {
protected:
int t1,t2;
};
TEST_F(CSquareRootTest, square1)  第一个参数必须等于类名



##	海量数据
4GB内存，对100GB文件排序
分为32个排好序的文件，从每个文件读入一个数据，形成一个32 元素的最小堆，从最小堆取走最小数据，如果对应的文件还没读完，取出下一个，读完不管，重新形成一个最小堆。再取走最小数据。如此循环
知道所有文件读完
