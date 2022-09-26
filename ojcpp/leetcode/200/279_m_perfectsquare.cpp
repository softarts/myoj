//
// Created by rui zhou on 30/01/19.
//

/*
 * https://leetcode.com/problems/perfect-squares/
 * Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.

 class Solution {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            if((int) Math.pow((int) Math.sqrt(i), 2) == i){
                dp[i] = 1;
            }
            else{
                int sqrt = (int) Math.sqrt(i);
                int j = 1;
                dp[i] = i;
                while(j <= sqrt){
                    dp[i] = Math.min(dp[i], 1 + dp[i - (int) Math.pow(j, 2)]);;
                    j++;
                }
            }
        }
        return dp[n];
    }
}
 */

#include <codech/codech_def.h>
#include <cmath>

using namespace std;
namespace {
    class Solution {
    public:
        //    思路，使用DP, 记录dp[i]为i所在perfect square个数,
//    dp[12]=dp[11]+dp[1]
//    dp[12]=dp[9]+dp[3]
//    dp[12]=dp[8]+dp[4] ->dp[8]=dp[4]+dp[4] ->dp[4]=1
//    dp[8]=dp[7]+dp[1],dp[6]+dp[2],dp[3]+dp[5],直到找到一个最小值
        int numSquares(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[1] = 1;
            for (int i = 1; i <= n; i++) {
                int sq = (int) sqrt(i);
                if (sq * sq == i) {
                    dp[i] = 1;
                    //cout << i << ":" << dp[i] <<std::endl;
                } else {
                    // e.g. i=2
                    dp[i] = i;  // init value to i dp[8]= 8个dp[1]
                    // 只需要遍历到sq即可,实则比较这几个值,dp[12],因为perfect square就是一个能取到最小的值
                    // dp[9]+dp[3]
                    // dp[4]+dp[8]
                    // dp[1]+dp[11]
                    //只更新到sqrt(i)为止
                    for (int j = 1; j <= sq; j++) {
                        dp[i] = min(dp[i], 1 + dp[i - j * j]);  // take previous perfect square
                        //cout << i << ":" << dp[i]<<std::endl;;
                    }
                }
            }
            return dp[n];
        }
    };

    class Solution1 {
    public:
//    loop1:1-12, dp[1]-dp[12]=1..12  (dp[1]+dp[1]....12)
//    loop2:4-12, 5-9必定以dp[4]为基础+1,dp[8]=1+dp[4],dp[9]=1+dp[8](3)
//    loop3:9-12,10-12再与dp[9]为基础,首先将dp[9]=1,然后再次更新dp[10]-dp[12]
//    每个循环开头都将1,4,9等设为1,很巧妙
//    为何分为3个循环?正好第一个循环做初始化，第二个循环只更新平方数之后的部分
        int numSquares(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[0] = 0;
            for (int num = 1; num * num <= n; num++) {
                for (int j = num * num; j <= n; j++) {
                    dp[j] = min(dp[j], 1 + dp[j - num * num]);
                    // 1+的原因是dp[num*num]=1
                    // dp[4] = min(4,1+dp[0])
                    // dp[8] = min(8,1+dp[4]) = 2
                    //cout << j << ":" << dp[j] << std::endl;
                }
            }
            return dp[n];
        }
    };

    class Solution2 {
    public:
        int numSquares1(int n) {
            vector<int> dp(n + 1, INT_MAX);
            dp[1] = 1;

            for (int i = 2; i <= n; i++) {
                int sq = (int) sqrt(i);
                if (sq * sq == i) {
                    dp[i] = 1;
                    cout << i << ":" << dp[i] << std::endl;;
                } else {
                    int sq = (int) sqrt(i);
                    int j = 1;
                    dp[i] = i;  // use '1'
                    while (j <= sq) {
                        dp[i] = min(dp[i], 1 + dp[i - j * j]);;
                        cout << i << ":" << dp[i] << std::endl;;
                        j++;
                    }
                }
            }
            return dp[n];
        }
    };
}

DEFINE_CODE_TEST(279_perfectsquare)
{
    Solution obj;
    {
        VERIFY_CASE(obj.numSquares(4),1);
        VERIFY_CASE(obj.numSquares(9),1);
        VERIFY_CASE(obj.numSquares(16),1);
        VERIFY_CASE(obj.numSquares(25),1);
        VERIFY_CASE(obj.numSquares(12),3);
        VERIFY_CASE(obj.numSquares(13),2);
        VERIFY_CASE(obj.numSquares(14),3);
        VERIFY_CASE(obj.numSquares(26),2);
        VERIFY_CASE(obj.numSquares(27),3);

    }
}