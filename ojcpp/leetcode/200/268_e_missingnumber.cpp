//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/missing-number/description/
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

 数组在0-n之间，找出missing的数字
 两种方法，1是计算0-n的和，然后减去数组中的和，差值为找的数字,但是sum可能溢出？
 2.
参与运算的两个值，如果两个相应位相同，则结果为0，否则为1。即：
0^0=0， 1^0=1， 0^1=1， 1^1=0

0^0=0,0^1=1 可以看出，0异或任何数＝任何数
1^0=1,1^1=0 可以看出 1异或任何数=任何数取反
任何数异或自己＝把自己置0

数a两次异或同一个数b（a=a^b^b）仍然为原值a.

 目的就是让
 举个例子，比如，我们得到一个数组[0,1,2,4,5],则res==5，在每一次for循环中，我们让5分别和i、nums[i]做异或运算，在5次循环后，
 res会和数列[0,1,2,3,4]和数组[0,1,2,4,5]都异或一遍，因为一个数a两次异或同一个数b（a=a^b^b）仍然为原值a，所以，
 初始值5在多次异或运算后，得到的结果就是只与5异或一次的数字，也就是缺的哪一个数字。

这种方法运用了位运算，计算十分快。
相当于每个数都尝试异或自身，最后剩下的就是没有异或自身的那个数字，即缺失的那个
 */

#include <codech/codech_def.h>
#include <numeric>
#include <vector>

using namespace std;
namespace {
    class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int result = nums.size();
            int i=0;
            for(int num:nums){
                result ^= num;
                result ^= i;
                i++;
            }

            return result;
        }
    };

    class Solution1 {
    public:
        int missingNumber(vector<int>& nums) {
            int64_t sum = accumulate(nums.begin(), nums.end(), 0);
            int n = nums.size();
            int64_t exp = (n+1)*n/2;
            return exp-sum;
        }
    };
}


DEFINE_CODE_TEST(268_missingnumber)
{
    Solution obj;
    vector<int> nums{3,0,1};
    VERIFY_CASE(obj.missingNumber(nums),2);

}