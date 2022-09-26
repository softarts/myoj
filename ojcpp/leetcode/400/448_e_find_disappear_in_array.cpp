//
// Created by rui zhou on 2019-08-28.
//

/*
 * https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int> ans;
            for (int i=0;i<nums.size();i++) {
                while (true) {
                    int cur = nums[i];
                    if (cur!=-1 && cur!=i+1) {
                        if (nums[cur-1]!=cur) {
                            swap(nums[i],nums[cur-1]);
                        } else {
                            nums[i] = -1;
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }

            for (int i=0;i<nums.size();i++) {
                if (nums[i]==-1)
                    ans.emplace_back(i+1);
            }
            return ans;
        }
    };
}

DEFINE_CODE_TEST(448_disappear_inarray) {
    Solution obj;
    {
        vector<int> nums{4,3,2,7,8,2,3,1};
        VERIFY_CASE(PRINT_VEC(obj.findDisappearedNumbers(nums)), "5 6");
    }
}

