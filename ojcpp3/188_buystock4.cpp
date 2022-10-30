#include <vector>
#include <iostream>
using namespace std;

/*
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
思路: 4,4,6 or 7,6=>
12:34
如何构造DP?
dp[i][0] (只允许1次交易)
dp[i][1] (只允许2次交易)
dp[i][j]= prices[i]-

首先局部最优解=> l[j] 第i天完成了第j次交易
*/
class Solution0 {
public:
// 没看懂 https://blog.csdn.net/linhuanmars/article/details/23236995
// 要用动态规划Dynamic programming来解，需要两个递推公式来分别更新两个变量local和global。
// 定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。
// 然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：
// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
// global[i][j] = max(local[i][j], global[i - 1][j])
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solveMaxProfit(prices);
        vector<int> g(k + 1,0);
        vector<int> l(k + 1,0);        
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};

// 这个解法非常精妙，而且我看得懂
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/2645267/JAVA%3A-O(n-*-k)-time-and-O(k)-space-or-With-Explanation-or-Easy-to-understand(Hopefully)
// 以这个为例， prices = [3,2,6,5,0,3], max profit= (3-0)+(6-2)， profit[2]+profit[1]
// 再转化为 3 - (0 - (6-2)) , 2就是第一次的cost, 6-2 就是第1次的profit, 然后 0 - (6-2)就是第二次的cost， 最后全部合起来就是第二次的profit
// 因为状态转移就是cost要最小化， profit最大化
// 推cost的转移方程时: 0 - (6-2) => curprice - 前一次的profit
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {        
        vector<int> profit(k,0);
        vector<int> cost(k, INT_MAX);        
        for(int currPrice : prices){
            cost[0] = min(cost[0], currPrice);
            profit[0] = max(profit[0], currPrice-cost[0]);

			for(int j = 1;  j < k; j++){
                cost[j] = min(cost[j], currPrice - profit[j-1]);
                profit[j] = max(profit[j], currPrice - cost[j]);
            }
       }
       return profit[k-1];
   }
};

//TLE
// class Solution {
// public:
//     int maxProfit(int k, vector<int> &prices) {
//         if (prices.empty()) return 0;
//         int n = prices.size();
//         if (k >= prices.size()) return solveMaxProfit(prices);
        
//         vector<vector<int> > f = vector<vector<int> >(n + 1, vector<int>(k + 1, 0));
//         for (int j = 1; j <= k; ++j) {
//             for (int i = 1; i <= n; ++i) {
//                 for (int x = 0; x <= i; ++x) {
//                     f[i][j] = max(f[i][j], f[x][j - 1] + profit(prices, x + 1, i));
//                 }
//             }
//         } 
//         return f[n][k];
//     }

//     // 这个就是求只限1次的txn的 maxprofit，
//     // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//     int profit(vector<int> &prices, int l, int u) {
//         if (l >= u) return 0;
//         int valley = INT_MAX;
//         int profit_max = 0;
//         for (int i = l - 1; i < u; ++i) {
//             profit_max = max(profit_max, prices[i] - valley);
//             valley = min(valley, prices[i]);
//             } 
//             return profit_max;
//         }

//     int solveMaxProfit(vector<int> &prices) {
//         int res = 0;
//         for (int i = 1; i < prices.size(); ++i) {
//             if (prices[i] - prices[i - 1] > 0) {
//                 res += prices[i] - prices[i - 1];
//             }
//         }
//         return res;
//     }
// };



int main() {
    Solution obj;
    {
        vector<int> arr{2,4,1};
        cout << boolalpha<<(obj.maxProfit(2,arr) == 2) << endl;
    }
    {
        vector<int> arr{3,2,6,5,0,3};
        cout << boolalpha<<(obj.maxProfit(2,arr) == 7) << endl;
    }
    {
        vector<int> arr{6,1,3,2,4,7};
        cout << boolalpha<<(obj.maxProfit(2,arr) == 7) << endl;
    }
    return 0;
}