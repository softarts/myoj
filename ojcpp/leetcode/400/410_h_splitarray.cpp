#include <codech/codech_def.h>
using namespace std;

/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays. 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4

// 这题有点难，没有思路
// 求极值,dp
将问题转化为二分法， 给定数组的最小值为数组的最大元素，最大值是数组的和，是否能找到一个位于这个范围之间的最小的数值
使其满足,是一个连续子数组的和，切分次数小于等于m-1
其中二分部分O(logN)，验证部分O(N)，合计O(N*LogN)
二分的模版
while (l<=r) {right=mid-1;left=mid+1}
*/

namespace {
    class Solution {
    public:
        int splitArray(vector<int>& nums, int m) {
            int left=0,right=0;
            for (int i=0;i<nums.size();i++) {
                left = max(left, nums[i]);
                right += nums[i];
            }
            
            while (left<=right) {
                int mid = (left+right)/2;
                //cout << "left "<< left <<","<<right<<" middle "<<mid<<endl;
                
                if (valid(nums,m-1,mid)) {
                    right=mid-1;  //如果不去掉mid，可能在最后l,r的时候导致l,r没有变化
                } else {
                    left=mid+1;
                }
                
            }
            return left;
        }
        
        bool valid(vector<int> &nums, int cuts, int target) {
            
            //cout<<"test "<<target<<endl;
            int curSum = 0;
            for (int i=0;i<nums.size();i++) {
                if (nums[i]>target) {
                    return false;
                } else if (curSum+nums[i]<=target) {
                    curSum+=nums[i];
                } else {
                    --cuts;
                    curSum=nums[i];
                    if (cuts<0) {
                        return false;
                    }
                }
            }
            return true;
        }
    };
}