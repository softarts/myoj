//
// Created by Rui Zhou on 16/3/18.
//

/*
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include <codech/codech_def.h>
#include <queue>

using namespace std;

namespace {
    class Solution0 {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int, vector<int>, greater<int>> queue;
            for (auto &n: nums) {
                queue.emplace(n);
                if (queue.size() > k ) {
                    queue.pop();
                }
            }
            return queue.top();
        }
    };

    // O(N) 的做法，参考nth_element
    class Solution1 {
        public:
            int findKthLargest(vector<int>& nums, int k) {
            int n = nums.size() - k;
            int low = 0;
            int high = nums.size() - 1;
            int cut = partition(nums, low, high);
            while (cut != n) {     
                if (cut < n) {
                    low = cut + 1;
                }
                else  {
                    high = cut - 1;
                } 
                cut = partition(nums, low, high);
            }
            return nums[n];
        }
        
        // 
        int partition(vector<int>&arr,int low,int high) {
            int pivot = arr[low];;//选第一个元素作为枢纽元
            while (low<high) {
                while (low < high && arr[high]>=pivot) high--;
                arr[low] = arr[high];
                while (low<high && arr[low]<=pivot) low++;
                arr[high] = arr[low];
                // 这里保证low,high两个位置都放入了正确的数字,
                // 最后退出时,low位置的数据挪去了high,应该更新为pivot
            }
            arr[low]=pivot;//?
            return low; 
            // 返回pivot所在的index, 如果low=1,说明pivot是low+1=2个小的数字
        }

    };

    // O(N)
    class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            auto m = nums.begin() + nums.size() - k;
            nth_element(nums.begin(), m, nums.end());
            return nums[nums.size() - k];
        }
    };

}



DEFINE_CODE_TEST(215_kth_largestelement_array)
{
    Solution obj;
    {
        vector<int> nums{3,2,1,5,6,4};
        VERIFY_CASE(obj.findKthLargest(nums, 2), 5);
    }
}

