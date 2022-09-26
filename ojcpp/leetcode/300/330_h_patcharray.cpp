//
// Created by Rui Zhou on 30/3/18.
//

/*
 * https://leetcode.com/problems/patching-array/description/
 * Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n] inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.

Example 1:
nums = [1, 3], n = 6
Return 1.

Combinations of nums are [1], [3], [1,3], which form possible sums of: 1, 3, 4.
Now if we add/patch 2 to nums, the combinations are: [1], [2], [3], [1,3], [2,3], [1,2,3].
Possible sums are 1, 2, 3, 4, 5, 6, which now covers the range [1, 6].
So we only need 1 patch.

Example 2:
nums = [1, 5, 10], n = 20
Return 2.
The two patches can be [2, 4].

Example 3:
nums = [1, 2, 2], n = 5
Return 0.

 //
 Idea: 1. Check the content if the current one is within sum +1, which is the total sum of all previous existing numbers. If yes, we proceed and update sum. If not, we patch one number that is within sum + 1.
2. Keep updating the sum until it reaches n.

 thoughts:
 [] --> 1
 1  --> 1
 1,2 -->3
 1,2,3 -->6  (3+4)
 1,2,3,4 ---> 10 (=4+7)
 1,2,3,4,5  --> 16
 */

#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long sum = 1;
        int idx = 0;
        int patch = 0;
        int count = 1;
        while (sum <= n) {
            if (idx < nums.size() && nums[idx] <= sum ) {
                sum += nums[idx++];
            } else {
                patch++;
                sum += sum;
            }
        }
        return patch;
    }
};

DEFINE_CODE_TEST(330_patcharray)
{
    Solution obj;
    {
        vector<int> nums{1,3};
        VERIFY_CASE(obj.minPatches(nums,6),1);
    }
    {
        vector<int> nums{1,2,2};
        VERIFY_CASE(obj.minPatches(nums,5),0);
    }
}
