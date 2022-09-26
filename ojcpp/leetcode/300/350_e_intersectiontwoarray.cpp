//
// Created by rui zhou on 17/03/18.
//

/*
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 * Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

 ->create two map, compare it?
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ret;
        size_t l = min(nums1.size(), nums2.size());

        int cur1 = 0, cur2 = 0;
        while (cur1!=nums1.size() && cur2!=nums2.size()) {
            int num1 = nums1[cur1];
            int num2 = nums2[cur2];
            if (num1==num2) {
                ret.push_back(num1);
                cur1++;
                cur2++;
            } else if (num1 < num2) {
                cur1++;
            } else {
                cur2++;
            }
        }
        return ret;
    }
};


DEFINE_CODE_TEST(350_intersection_array)
{
    Solution obj;
    {
        vector<int> nums1{1,2,2,1};
        vector<int> nums2{2,2};
        VERIFY_CASE(PRINT_VEC(obj.intersect(nums1, nums2)),"2 2");
    }
}