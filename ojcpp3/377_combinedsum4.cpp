#include <vector>
#include <iostream>
using namespace std;

/*
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
*/
//TLE
// 并不需要lc39那样找出所有答案，而只需要得到总的计数
// 但仍然TLE, 猜测可以用memo
class Solution0 {
public:    
    int sum=0;
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());         
        helper(nums, target);
        return sum; 
    }


    void helper(vector<int>& nums, int target) {
        if (target==0) {       
            sum++;
            return;
        }

        for (int i=0;i<nums.size()&&target>=nums[i];i++) {            
            helper(nums, target-nums[i]);
        }
    }
};

//memo
// 使用一个dp来记下前面的计算结果
class Solution {
public:        
    vector<int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        // 初始化dp都没有记忆
        dp.resize(target+1,-1);
        return helper(nums, target);
    }


    int helper(vector<int>& nums, int target) {
        if (target==0) {       
            return 1;
        }
        if (dp[target]!=-1) return dp[target];

        int ans=0;

        for (int i=0;i<nums.size();i++) {            
            if (nums[i]<=target) {
                ans+=helper(nums, target-nums[i]);
            }
        }
        return dp[target]=ans;// return ans;
    }
};