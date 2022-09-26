#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

// 开始想过用递归，肯定会TLE
// DP的思路, 每一个amount的个数都和前一个状态有关
// 每加入一个coin,都表示从前面的dp[i-coin]的状态多了一个路径到dp[i]，此情况下dp[i]是累加的
// 因为，对于每种coin（第一层循环）我们都能计算出一个dp[i]。
// 例如已有$1, 如果加入一个$2的话，那么dp[4]的计数就=dp[2]+之前的dp[4]==>3
// 再加入一个$3，那么dp[4]=dp[1]+之前的dp[4](3)==>4
namespace {
    class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            vector<int> dp(amount+1,0);
            dp[0]=1;
            for (int coin:coins) {
                for (int i=coin;i<=amount;i++) {
                    dp[i]+=dp[i-coin];
                }
            }
            return dp[amount];
        }
    };
}