//
// Created by rui zhou on 2019-09-18.
//


/*
 *You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.



Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation:
You throw one die with 6 faces.  There is only one way to get a sum of 3.
Example 2:

Input: d = 2, f = 6, target = 7
Output: 6
Explanation:
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: d = 2, f = 5, target = 10
Output: 1
Explanation:
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
Example 4:

Input: d = 1, f = 2, target = 3
Output: 0
Explanation:
You throw one die with 2 faces.  There is no way to get a sum of 3.
Example 5:

Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation:
The answer must be returned modulo 10^9 + 7.


Constraints:

1 <= d, f <= 30
1 <= target <= 1000
 问有多少种办法得到target sum，和hht略有不同
 可能用backtracking更好
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    // DP
    class Solution {
    public:
        int numRollsToTarget(int d, int f, int target) {
            vector<unordered_map<int,long>> dp(d+1);
            for (int j=1;j<=target;j++) {
                if (j<=f) dp[1][j] = 1;
            }

            for (int i=2;i<=d;i++) {
                for (int k=i;k<=target;k++) {  // j取值为i~i*f
                    for (int j=1;j<=f&&k>j;j++) {
                        dp[i][k] += dp[i-1][k-j];
                    }
                    dp[i][k] %= 1000000007;
                }
            }
            return dp[d][target];

//            vector<vector<long long>> dp(d+1, vector<long long>(target+1, 0));
//            for(int j=1; j<=target; j++) {
//                if (j <= f) dp[1][j] = 1;
//            }
//            for(int i=2; i<=d; i++) {
//                for(int k=1; k<=target; k++) {
//                    for(int j=1; j<=f; j++) {
//                        if (k > j) dp[i][k] += dp[i-1][k-j];
//                    }
//                    //dp[i][k] %= 1000000007;
//                }
//            }
//            return dp[d][target];// % 1000000007;
        }
    };
}

DEFINE_CODE_TEST(1155_dicetargetsum)
{
    {
        Solution obj;
        VERIFY_CASE(obj.numRollsToTarget(2,6,7),6);
    }
    {
        Solution obj;
        VERIFY_CASE(obj.numRollsToTarget(2,5,10),1);
    }

    {
        Solution obj;
        VERIFY_CASE(obj.numRollsToTarget(1,6,3),1);
    }



}
