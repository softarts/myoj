//
// Created by Rui Zhou on 30/3/18.
//

/*
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

意思是返回当前的index,但要使用比O(N)更好的算法
must be better than O(N), solved by binary_search
 */

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    /*   完全不对
    int search0(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int prev = nums[0];
        int pivot = 0;
        int idx = -1;
        for (int i=0;i < nums.size(); i++) {
            if (nums[i] < prev) {
                pivot = i;
            }
            if (nums[i] == target) {
                idx = i;
            }
            prev = nums[i];
        }

        if (pivot==0)
            return idx;
        if (idx <pivot && idx >=0) {
            idx = idx + pivot;
        } else if (idx>=pivot){
            int offset = nums.size()-pivot;
            idx = idx - offset;
        }
        return idx;
    }*/



    int search0(vector<int>& nums, int target) {
        int lo = 0, hi = int(nums.size()) - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo == hi && nums[lo] == target ? lo : -1;
    }

    // 4 5 6 7 0 1 2
    //good
    int search1(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi) {
            int mid = (hi+lo)/2;
            if (nums[mid]==target)
                return mid;
            if (nums[mid] > nums[hi]) { // rotation right part
                if (target < nums[mid] && target >= nums[lo]) {
                    hi = mid - 1;
                } else {  // 4 5 6 7 8 9 11(mid) 12 13 14 0 1 2 3
                    lo = mid + 1;
                }
            } else if (nums[mid] < nums[lo]) { // rotation left part
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid+1;
                } else {
                    hi = mid - 1;
                }
            } else {  // no rotation
                if (target > nums[mid]) {
                    lo = mid+1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }

    // 没做出来，很可惜
    // 4567012, 原来通过和mid比较知道属于哪个半区，现在不能了

    // [4,5,6,7,8,9,0,1,2]
    // 9
    // 通过target 和mid，以及mid和end之间的大小关系来判断边界条件，有点麻烦，主要是太复杂，
    // 先从整体上分成2个区域
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while (start<=end) {
            int mid = (start+end)/2;
            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid]>nums[end]) {
                // right part rotated
                if (target<nums[mid] && target >= nums[start]) {
                    end=mid-1; // 只有这种情况需要search in left
                } else {
                    start = mid+1; // search in right
                }
            } else if (nums[mid] < nums[start]) {
                //left part rotated
                if (target>nums[mid] && target <=nums[end]) { //right is sort
                    start = mid + 1;
                } else {
                    end = mid-1;
                }
            } else { // no rotation
                if (target>nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;//如果前面while (<)的话就需要退出时再判断一次
    }



};

DEFINE_CODE_TEST(033_search_in_rotated_array)
{
    Solution obj;

    {
        vector<int> nums{3,5, 1};
        VERIFY_CASE(obj.search(nums,3),0);
    }
    {
        vector<int> nums{3,1};
        VERIFY_CASE(obj.search(nums,1),1);
    }
    {
        vector<int> nums{1,3};
        VERIFY_CASE(obj.search(nums,1),0);
    }


    {
        vector<int> nums{1};
        VERIFY_CASE(obj.search(nums,1),0);
    }
    {
        vector<int> nums{4,5,6,7,0,1,2,3};
        VERIFY_CASE(obj.search(nums,1),5);
    }

}