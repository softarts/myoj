//
// Created by rui.zhou on 3/14/2019.
//

/* amazon
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
 * You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * Return the max sliding window.

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Note:
You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
 找出滑动窗口的最大值,用priority_queue可以解决,但需要记录最大值和index，
 能否做到O(N)?用deque,由于是滑动窗口，一旦新出现一个更大的值(时间更新)，那么前面所保存的较小的值都会失效的

 */
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc239 {
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ret;
            deque<int> deq;

            for (int i=0;i<nums.size();i++) {
                while (!deq.empty() && nums[i]>deq.back()) {
                    deq.pop_back();
                }
                deq.emplace_back(nums[i]);

                if (i>=k && deq.front() == nums[i-k]) {  //invalid expire max
                    deq.pop_front();
                }

                if (i>=k-1) {
                    ret.emplace_back(deq.front());
                }
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(239_slidingwindowmaximum)
{
    lc239::Solution obj;
    {
        vector<int> nums{1,3,-1,-3,5,3,6,7};
        //vector<int> exp{1,3,-1,-3,5,3,6,7};
        VERIFY_CASE(VERIFY_VEC(obj.maxSlidingWindow(nums,1),{1,3,-1,-3,5,3,6,7}),true);
    }
    {
        vector<int> nums{};
        vector<int> exp{};
        VERIFY_CASE(VERIFY_VEC(obj.maxSlidingWindow(nums,3),{}),true);
    }
    {
        vector<int> nums{1,3,-1,-3,5,3,6,7};
        //vector<int> exp{1,3,-1,-3,5,3,6,7};
        VERIFY_CASE(VERIFY_VEC(obj.maxSlidingWindow(nums,1),{1,3,-1,-3,5,3,6,7}),true);
    }
}