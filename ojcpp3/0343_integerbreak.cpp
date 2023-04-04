#include <iostream>
#include <vector>
/*
思路，一次AC，还是不错的，前面有许多类似的题目
就是从小到大，把i拆分为比他小的组合，利用动态规划迭代得到最大值
一般求极值都会用到动态规划
*/
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(59,1);
        for (int i=2;i<=n;i++) {
            for (int j=1;j<=i/2;j++) {
                dp[i] = max(dp[i], max(dp[j],j) * max(dp[i-j],i-j));
                //cout <<"dp["<<i<<"]= " << dp[i] << endl;
            }
        }
        return dp[n];
    }
};