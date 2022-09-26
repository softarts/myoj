//
// Created by rui.zhou on 2/26/2019.
//

/*
 * amazon
 * [LintCode] 533 Two Sum - Closest to target locked
Description
Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

Return the difference between the sum of the two integers and the target.

Example
Given array nums = [-1, 2, 1, -4], and target = 4.
The minimum difference is 1. (4 - (2 + 1) = 1).



Challenge
Do it in O(nlogn) time complexity.

*/
#include <codech/codech_def.h>
using namespace std;

class Solution {
    /**
     * @param nums an integer array
     * @param target an integer
     * @return the difference between the sum and the target
     */
public:
    int twoSumClosest(vector<int> nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int minDist=INT_MAX;
        while (l<r) {
            int sum=nums[l]+nums[r];
            minDist=min(minDist,abs(target-sum));
            if (sum == target) {
                return 0;
            } else if (sum>target) {
                r--;
            } else {
                l++;
            }
        }
        return minDist;
    }
};

DEFINE_CODE_TEST(lint_533_twosumclosest)
{
    Solution obj;
    {
        vector<int> nums{-1,2,1,-4};
        VERIFY_CASE(obj.twoSumClosest(nums,4),1);
    }

}
