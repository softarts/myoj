//
// Created by Rui Zhou on 23/3/18.
//

/*
 * https://leetcode.com/problems/move-zeroes/description/
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
10:24 am->

 w 作为0 的写入位置,每遇到不为0的数字就和w位置交换
 */

#include <codech/codech_def.h>
#include <vector>
#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int w = 0;
        for (int i = 0; i< nums.size(); i++) {
            if (nums[i]!=0) {
                swap(nums[w++], nums[i]);
            }
        }
    }
};

DEFINE_CODE_TEST(283_movezero)
{
    Solution obj;
    {
        vector<int> nums{0,1,0,3,12};
        obj.moveZeroes(nums);
        VERIFY_CASE(PRINT_VEC(std::move(nums)),"1 3 12 0 0");
    }
    {
        vector<int> nums{5,0,1,0,3,12};
        obj.moveZeroes(nums);
        VERIFY_CASE(PRINT_VEC(std::move(nums)),"5 1 3 12 0 0");
    }
    {
        vector<int> nums{5,4,1,3,3,12};
        obj.moveZeroes(nums);
        VERIFY_CASE(PRINT_VEC(std::move(nums)),"5 4 1 3 3 12");
    }

}