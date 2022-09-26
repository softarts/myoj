//
// Created by rui zhou on 31/03/19.
//

/*
 * Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

 -> 难以判断触发点？1,2,3,0,2,5
 backtracking？

 int maxProfit(int* prices, int pricesSize) {
    if(pricesSize<2){
        return 0;
    }
    int* buy=(int*)calloc((pricesSize+1),sizeof(int));
    int* sell=(int*)calloc((pricesSize+1),sizeof(int));
    buy[1]=-prices[0];
    for(int i=2;i<=pricesSize;i++){
        buy[i]=max(sell[i-2]-prices[i-1],buy[i-1]);
        sell[i]=max(sell[i-1],buy[i-1]+prices[i-1]);
    }
    return sell[pricesSize];
}

 var maxProfit = function(prices) {
    if (prices.length <= 1) return 0
    var dp = []
    for (let i = 0; i < prices.length; i++) {
        dp[i] = []
    }

    dp[0][0] = 0
    dp[0][1] = -prices[0]
    dp[0][2] = Number.MIN_VALUE
    for (let i = 1; i < prices.length; i++)  {
        dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][2]) //rest
        dp[i][1] = Math.max(dp[i - 1][0] - prices[i], dp[i - 1][1]) //buy status
        dp[i][2] = Math.max(dp[i - 1][0], dp[i - 1][1] + prices[i]) //sell status
    }
    return Math.max(dp[prices.length - 1][0], dp[prices.length - 1][2])
}
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int total=0;
            int n=prices.size();
            vector<int> buy(n,0),sell(n,0),rest(n,0);
            buy[0]=-prices[0];
            for (int i=1;i<prices.size();i++) {
                buy[i]=max(rest[i-1]-prices[i],buy[i-1]);  // 前一天是持有状态，前一天是冷静期过后买入,谁更好
                sell[i]=max(buy[i-1]+prices[i],sell[i-1]); // 比较前一天sell和今天sell谁更好
                rest[i]=max({buy[i-1],sell[i-1],rest[i-1]});
            }
            return max(rest[n-1],sell[n-1]);
        }
    };
}


DEFINE_CODE_TEST(309_buystock_cooldown)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,0,2};
        VERIFY_CASE(obj.maxProfit(nums),3);
    }
}