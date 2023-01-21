
/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
TODO 有空再写个暴力解题法

*/
#include <cstring>
using namespace std;

class Solution {
public:
    // pos, count, limit, 需要对limit进行区分，因为允许的取值范围不一样
    // dp[3][1][0]指第三位,当前面（左侧）1的个数为1，无limit限制时的digit为1的数字的个数 
    // 21345， 当前面为21的时候,3有limit,只能取0～3，dp[3][count][limit=1] = x
    // 当前面是其他数字，3位没有limit,可以取0~9, dp[3][count][0] = y
    // 上面可以看出for loop的范围不一样(ub),那么res的值肯定不同
    // 本题是一个backtracking 的问题，采用了递归和记忆的办法,其实不能算dp动态规划
    int dp[14][14][2];
    int a[14];
    // 这里首先把n拆分为一个数组，从高到低开始遍历
    // 21345=> [-,5,4,3,1,2], 从2开始递归
    int countDigitOne(int n) {
        memset(dp, -1, sizeof dp);
        int len=0;
        while (n>0) {
            a[++len] = n%10;
            n/=10;
        }
        return helper(len,0,1);
    }


    int helper(int pos,int count, int limit) {
        // 终止状态的话，如果遍历到了最后一位结束，就返回 count 数量就行了，表示当前数字中有 count 个 1 。
        if (!pos) return count;
        // 记忆，剪枝            
        if (dp[pos][count][limit]!=-1) return dp[pos][count][limit];
        // 如果是limit的话，限制了本pos所能取的数字的范围
        int ub=limit?a[pos]:9;
        int res = 0;
        for (int i=0;i<=ub;++i) {
            //limit&&i==a[pos] 必须两个条件均成立才为限制， 21345, 只有1位是2，那么第二位才是limit, 并且=1的时候，才把limit传到下一位去
            res +=helper(pos-1, count+(i==1), limit&&i==a[pos]);
        }
        dp[pos][count][limit]=res;
        return res;
    }
};
