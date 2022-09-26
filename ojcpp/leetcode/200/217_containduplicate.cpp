//
// Created by Rui Zhou on 10/3/18.
//

/*
 * https://leetcode.com/problems/contains-duplicate/description/
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value
 * appears at least twice in the array, and it should return false if every element is distinct.

 10:49
 1.使用hashset?
 2. sort O(nLogN),再比较前后是否一致
 2.如果限制O(1)?
 */

#include <codech/codech_def.h>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset(nums.begin(), nums.end());
        return (myset.size() < nums.size());
    }
};

DEFINE_CODE_TEST(217_containduplicate)
{
    vector<int> nums{1,2,3,4,5,5,4};
    Solution obj;
    VERIFY_CASE(obj.containsDuplicate(nums), true);
}