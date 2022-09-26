//
// Created by rui zhou on 24/03/18.
//


/*
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 * Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

**DP
找出最长递增队列的长度

 */

#include <codech/codech_def.h>
#include <climits>
#include <vector>

using namespace std;
namespace {
    class Solution {
    public:
        // time limit exceed.
        int lengthOfLIS(vector<int> &nums) {
            return subLength(nums, INT_MIN, 0);
        }

        int subLength(vector<int> &nums, int prev, int curpos) {
            // exit cond
            if (curpos == nums.size())
                return 0;
            int taken = 0;
            if (nums[curpos] > prev) {
                taken = 1 + subLength(nums, nums[curpos], curpos + 1);
            }
            int nottaken = subLength(nums, prev, curpos + 1);
            return max(taken, nottaken);
        }
    };

    class Solution1 {
    public:
        // dp[i]= longest increasing sequence, iterate 0~i to update dp[i]
        // dp[i] 到i为止前面有多少个递增数字
        int lengthOfLIS(vector<int>& nums) {
            vector<int> dp(nums.size(), 1);
            int res = 0;
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    if (nums[i] > nums[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
                res = max(res, dp[i]);
            }
            return res;
        }

    };
}



DEFINE_CODE_TEST(300_longest_increasing_subsequence)
{
    Solution1 obj;
    {
        vector<int> nums{10,9,2,5,3,7,101,18};  //4
        VERIFY_CASE(obj.lengthOfLIS(nums),4);
    }

    {
        vector<int> nums{10,11,2,5,7,3,8,9,10};  //6
        VERIFY_CASE(obj.lengthOfLIS(nums),6);
    }

    {
        vector<int> nums{10,11,2,5,7,3,4,5,6};  //5
        VERIFY_CASE(obj.lengthOfLIS(nums),5);
    }
}