//
// Created by rui.zhou on 5/6/2019.
//

//LC 053
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int findMaxSumSubArray(vector<int>& nums) {
            vector<int> dp(nums.size(),0);            ;
            dp[0]=nums[0];
            int maxSum = dp[0];
            for (int i=1;i<nums.size();i++) {
                dp[i] = max(dp[i-1]+nums[i],nums[i]);
                maxSum = max(maxSum, dp[i]);
            }
            return maxSum;
        }
    };
}