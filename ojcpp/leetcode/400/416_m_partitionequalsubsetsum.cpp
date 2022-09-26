//
// Created by rui zhou on 2019-09-22.
//

/*
 * Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.


Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
 */

#include <codech/codech_def.h>
#include <numeric>

using namespace std;

namespace {
    // 这个做法很cool,计算出总数，然后寻找sum=total/2的可能性，使用了一个nest loop来列举所有的sum的可能性，依次把sum加入到set里面，
    // 再把每个数和 sum的每个可能相加，得到一个新的sum，然后再加入到sum之中
    class Solution0 {
    public:
        bool canPartition(vector<int>& nums) {
            int total = 0;
            total = std::accumulate(nums.begin(),nums.end(),0);

            if (total % 2 != 0) {
                return false;
            }

            unordered_set<short> sums(total / 2);
            for (int n : nums) {
                vector<short> vec;
                vec.push_back(n);
                for (auto it = sums.begin(); it != sums.end(); it++) {
                    if (n + *it <= total / 2) {
                        vec.push_back(n + *it);
                    }
                }
                sums.insert(vec.begin(), vec.end());
            }
            return (sums.find(total / 2) != sums.end());
        }
    };
    /*
     * def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        target = total // 2
        dp = [False] * (target + 1)
        dp[0] = True
        for num in nums:
            for i in range(target, num - 1, -1):
                dp[i] = dp[i] or dp[i - num]
        return dp[target]
     */
    //将题目转化为dp[target]是否存在，而不是一直在考虑分组的问题
    // dp 表示 [0...target]的存在的可能性
    class Solution {
    public:
        bool canPartition(vector<int> &nums) {

        }
    };

}


