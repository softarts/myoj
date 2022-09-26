//
// Created by rui zhou on 2019-08-30.
//

/*
 * You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    // brute force
    class Solution0 {
    public:
        int target = 0;
        int ans = 0;
        int findTargetSumWays(vector<int>& nums, int S) {
            target = S;
            vector<int> comb;
            dfs(nums,0,0,comb);
            return ans;
        }

        void dfs(vector<int> &nums, int start, int sum, vector<int> &comb) {
            if (start==nums.size()) {
                if (sum==target) {
                    //PRINT_VEC(move(comb));
                    ans++;
                    return;
                } else {
                    return;
                }
            }

            //comb.emplace_back(nums[start]);
            dfs(nums,start+1,sum+nums[start],comb);
            //comb.pop_back();
            //comb.emplace_back(-nums[start]);
            dfs(nums,start+1,sum-nums[start],comb);
            //comb.pop_back();
        }
    };

    // 记忆法更好,只要index和sum相同，后面的结果也相同
    class Solution1 {
    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            vector<vector<int>> memo(nums.size(),vector<int>(2000,INT_MAX));
            return dfs(nums,0,0,S,memo);
        }

        int dfs(vector<int> &nums, int start, int sum, int target, vector<vector<int>> &memo) {
            if (start==nums.size()) {
                if (sum==target) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (memo[start][sum+1000] != INT_MAX)
                    return memo[start][sum+1000];

                int add = dfs(nums,start+1,sum+nums[start],target, memo);
                int sub = dfs(nums,start+1,sum-nums[start],target,memo);
                memo[start][sum+1000] = add+sub;
                return memo[start][sum+1000];
            }

        }
    };
    /*
     * public class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        int[][] dp = new int[nums.length][2001];
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < nums.length; i++) {
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[i - 1][sum + 1000] > 0) {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[nums.length - 1][S + 1000];
    }
}
     */
    // DP
    class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            vector<vector<int>> dp(nums.size(),vector<int>(2001,0));
            dp[0][nums[0] + 1000] = 1;
            dp[0][-nums[0] + 1000] += 1;
            for (size_t i=1;i<nums.size();i++) {
                for (int sum=-1000;sum<=1000;sum++) {
                    if (dp[i-1][sum+1000] > 0 ) {
                        dp[i][sum+nums[i]+1000] = dp[i-1][sum+1000];
                        dp[i][sum-nums[i]+1000] += dp[i-1][sum+1000];
                    }
                }
            }
            return S>1000?0:dp[nums.size()-1][S+1000];

        }
    };

}

DEFINE_CODE_TEST(494_targetsum)
{
    {
        Solution obj;
        vector<int> nums{1,1,1,1,1};
        VERIFY_CASE(obj.findTargetSumWays(nums,3),5);
    }
}