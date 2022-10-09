#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2

// 这个题目和523类似，以及1048? 太精彩了,利用hashmap来递推 
// 使用一个字典保存数组某个位置之前的数组和，然后遍历数组求和，
// 这样当我们求到一个位置的和的时候，向前找sum-k是否在数组中，
// 如果在的话，更新结果为之前的结果+(sum-k出现的次数)。同时，当前这个sum出现的次数就多了一次。

// m[0]=1; 累加sum, 然后m[sum]=1, 这样，当累积到下一个sum+k的时候，即之间的和=k,那么就找到一个subarry_sum=k
// 如何判断然后记录
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        unordered_map<int,int> m{{0,1}};          
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if (m.count(sum-k)) {
                ans+=m[sum-k]; // ans+上前一次的结果
            }
            
            m[sum]++;  // 后面如果再出现(sum+k)，类似上一行的做法
        }
        return ans;
    }
};

// int subarraySum(vector<int>& nums, int k) {
//         int ans = 0;
//         unordered_map<int,int> m{{0,1}};
//         int sum = 0;
//         for (size_t i=0;i < nums.size();i++) {
//             sum += nums[i];
//             ans += m[sum-k];
//             m[sum]++;
//         }
//         return ans;  
//     }