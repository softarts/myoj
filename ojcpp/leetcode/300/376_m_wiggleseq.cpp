//
// Created by rui.zhou on 3/11/2019.
//

/* greedy
 * A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Example 1:

Input: [1,7,4,9,2,5]
Output: 6
Explanation: The entire sequence is a wiggle sequence.
Example 2:

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
Explanation: There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
Example 3:

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?
 2:29
 前后两个差是否符号相反
 没思路,想复杂了，就是暴力看前一个的差和本个的差相乘是否<=0,
 */

#include <codech/codech_def.h>
using namespace std;

namespace lc376 {
    class Solution {
    public:

        int wiggleMaxLength(vector<int>& nums) {
            if (nums.size()<2)
                return nums.size();
            int ans=1;
            int dif = nums[1]-nums[0];
            if (dif!=0) ans+=1;
            for (int i=2;i<nums.size();i++) {
                if (nums[i]!=nums[i-1]) {
                    if ((nums[i]-nums[i-1])*dif<=0) {  //只要后面有相邻的构成wiggle就可以了
                        //=0的原因是第一个dif可能=0
                        // 需要排除划掉这个元素不会影响结果正确性
                        //贪心算法保证的，跳过不合适的
                        ans+=1;
                        dif=nums[i]-nums[i-1];
                    }
                }
            }
            return ans;
        }
    };
}

DEFINE_CODE_TEST(376_wiggleseq)
{
    lc376::Solution obj;
    {
        vector<int> nums{17,5,10,18,17};
        VERIFY_CASE(obj.wiggleMaxLength(nums),4);
    }
    {
        vector<int> nums{1,7,4,9,2,5};
        VERIFY_CASE(obj.wiggleMaxLength(nums),6);
    }
    {
        vector<int> nums{1,17,5,10,13,15,10,5,16,8};
        VERIFY_CASE(obj.wiggleMaxLength(nums),7);
    }
    {
        vector<int> nums{1,2,3,4,5,6,7,8,9};
        VERIFY_CASE(obj.wiggleMaxLength(nums),2);
    }

}