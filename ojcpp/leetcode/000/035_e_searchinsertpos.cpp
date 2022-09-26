//
// Created by rui zhou on 11/02/19.
//

/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
与004有所不同，不是分配元素的个数，而是求mid 的index,范围应该是start<end(sizeof_vector)
xxxxxx
二分法必须是start<=end (end=size-1)
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1,mid;
        while (start<=end) {
            mid = (end+start)/2;
            if (nums[mid]>target) {
                end = mid-1;
            } else if (nums[mid] < target) {
                start = mid+1;
            } else {
                return mid;
            }

        }
        return target>nums[mid]?mid+1:mid;
    }
};


DEFINE_CODE_TEST(035_searchinsertpos) {
    Solution obj;
    {
        vector<int> nums{1,2,3,4,5,6,7};
        VERIFY_CASE(obj.searchInsert(nums,4),3);
        VERIFY_CASE(obj.searchInsert(nums,8),7);
    }
    {
        vector<int> nums{1,2,3,5,6,7,8};
        VERIFY_CASE(obj.searchInsert(nums,4),3);
    }
}