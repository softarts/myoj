#include <vector>
#include <iostream>
using namespace std;

// 10:47PM 2021-10-31二刷
// fewest way-> 求极值， DP !这个很重要
// dp[x] 记录每一个target所能取到的min steps
// 例如 dp[11]=dp[5]+dp[5]+dp[1] =1+1+1
// 取得可用的coin，然后对整个amount的dp进行更新
// dp[i]表示i所在位置需要的coin minimum个数
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1); //max=amount+1,因为最小面值就是$1
        dp[0]=0;
        for (auto c:coins) {
            // dp[c] = 1; 不要设置这里 避免overflow, [1], amount=0
            for (int i=c;i<=amount;i++) {
                dp[i] = min(dp[i],dp[i-c]+1); 
                //如果i==c,那么正好需要1个,假如i-c=1，那么需要1(dp[c])+dp[1]
            }
        }
        return dp[amount]>amount?:-1:dp[amount];        
    }
};