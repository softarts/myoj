#include <vector>
#include <queue>
#include <iostream>
#include <array>
using namespace std;

/*
超级丑数的素因子不再仅限于2 3 5，而是由题目给定一个素数数组, 因子只在这些数组中
逐个计算肯定会TLE
和素数的筛法类似, 

Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].

ugly=1, 
1x 2,7,13,19 => 1,2,7,13,19 (ugly:1,2)
2x 2,7,13,19 => 4,14,26,38... => 1,2,4,7,13,14,19,26... (1,2,4)
4x 2,7,13,19 => 8,28,52,76...=> 1,2,4,7,8,13,14,19,26,28 (1,2,4,7) 
7x 2,7,13,19
8x,2,7,13,19...  =>1,2,4,7,8,13,(16)...

TLE, 这里的缺点，有些ugly 都是从0开始loop，必然有重复计算
100000
[7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251]
问题:
1x7 这里怎么把得到7的时间提前
记录每个ugly已经和primes相乘的下标，这样就只计算未相乘的,如果
pattern是:每一个现有的ugly，都和primes相乘，得到一个最小的ugly(比现有的大)，再放到ugly数组中
*/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // 和对应的primes已经相乘的ugly的下标
        // 不允许可变下标 ={}初始化
        // int memo[primes.size()]={};
        vector<int> memo(primes.size(),0);
        // for (int i=0;i<primes.size();i++) {
        //     cout  << memo[i] << endl;
        // }
        //std::array<int, primes.size()> memo{0}; 
        long ugly[n];
        ugly[0]=1;

        for (int i=1;i<n;i++) {
            long minv=LONG_MAX;
            int minvidx = -1;
            for (int j=0;j<primes.size();j++) {
                while (ugly[memo[j]]*long(primes[j])<=ugly[i-1]) {
                    // primes 逐个x memo[j]的当前指向的ugly，得到 val
                    // val小于当前ugly,则么memo[j]需要++，用下一个ugly，
                    // 即这个memo[j]指向的ugly需要忽略，因为小于当前计算的ugly
                    memo[j]++;
                    // 
                }
                // 找出所有primes x所能得到的最小ugly，记下miv,minvidx
                if ((primes[j] * ugly[memo[j]]) < minv) {
                    minv = primes[j] * ugly[memo[j]];
                    minvidx = j;
                }
            }
            ugly[i]=minv;
            memo[minvidx]++; //选中的那个memo的指针++
        }
        return ugly[n-1];

    }

    //TLE
    int nthSuperUglyNumber0(int n, vector<int>& primes) {
        //TLE, 如何避免从第一个ugly开始loop?
        long ugly[n];
        ugly[0]=1;
        int ptr=0;
        while (ptr<n-1) {
            long minv=LONG_MAX;
            bool flag=true;
            cout << "working " << ptr << endl;
            for (int i=0;i<=ptr;i++) {
                for (int j=0;j<primes.size();j++) {
                    if (ugly[i]*long(primes[j])>ugly[ptr]) {
                        minv = min(minv,ugly[i]*primes[j]);
                        flag=false;break;
                    }
                }
                if (!flag) break;
            }
            ugly[++ptr] = minv;
        }
        return ugly[n-1];
    }
};
int main() {
    int sz=100000;
    vector<int> nums{7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
    Solution obj;
    cout << obj.nthSuperUglyNumber(sz,nums);
    return 0;
}