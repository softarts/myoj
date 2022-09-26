//
// Created by rui zhou on 24/03/18.
//

/*
 * https://leetcode.com/problems/product-of-array-except-self/description/
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is
 * equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for
 the purpose of space complexity analysis.)

 输出数组，每个元素为等于其他所有数的乘积，不可以用除法。
 */

#include <codech/codech_def.h>
#include <vector>
#include <codech/algo_common.h>


using namespace std;
using namespace CODECH;
namespace {
    class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res(nums.size(), 1);
            int product = 1;
            for (int i = 1; i < nums.size(); i++) {
                product = product * nums[i-1];
                res[i] = product;
            }

            product = 1;
            for (int i = nums.size()-2; i >= 0; i--) {
                product = product * nums[i+1];
                res[i] = res[i]*product;
            }
            return res;
        }
    };


    class Solution1 {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res(nums.size(), 1);
            int left = 1,right=1;
            for (int i = 0; i < nums.size(); i++) {
                res[i] *= left;
                left *= nums[i];
            }

            for (int i = nums.size()-1; i >= 0; i--) {
                res[i] *= right;
                right *= nums[i];
            }
            return res;
        }
    };
}



DEFINE_CODE_TEST(238_product_of_array_except_self)
{
    Solution obj;
    {
        vector<int> nums{1,2,3,4};
        VERIFY_CASE(PRINT_VEC(obj.productExceptSelf(nums)),"24 12 8 6");
    }
}