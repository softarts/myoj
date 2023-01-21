#include <vector>
#include <algorithm>

using namespace std;
/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 
Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

这个题目非常不清晰,annswer[i],j都是哪些？任意一对？
使用backtracking
带记忆，需要做笔记记下来
对于这种带条件的不太能用dfs里再用for()，因为最后退出时还要再处理一遍 
要么是一个返回数据的dfs
非常好的一道bt + 剪枝 + dp的题目
*/
class Solution0 {
public:
// 这个解法的思路是递归，退出条件是到达终点，或者当前数字不是前一个的倍数
// 1 4 8 12 16 48 96
// 剪枝的目的减少运算量, 48处保存了该位置的vector{48,96}， 无论前面是12还是16，都可以直接取这个vector
// 需要依次取每一个元素进行尝试。 
    vector<int> ans;
    vector<vector<int>> memo;
    vector<bool> visited;
    
    vector<int> helper(vector<int>& nums, int index, int prevNum) {
        int cur = nums[index];
        if (cur % prevNum!=0) {
            return vector<int>();
        }
        // 剪枝的目的减少运算量, 不然TLE
        if (visited[index]) return memo[index];        

        vector<int> vec = vector<int>();
        for (int i=index+1;i<nums.size();i++) {
            auto ret = helper(nums,i,cur);
            if (ret.size() > vec.size()) {
                vec = ret; 
            }
        }
        vec.push_back(cur);
        visited[index]=true;
        memo[index] = vec;
        return vec;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        visited.resize(n,false);
        memo.resize(n,vector<int>());

        for (int i=0;i<nums.size();i++) {
            vector<int> ret = helper(nums,i,1);
            if (ret.size()>ans.size()) {
                ans=ret;
            }
        }
        return ans;
    }

    

};


// for (int i=start;i<nums.size();i++) {
//     if (memo.empty()) {
//         memo.push_back(nums[i]);
//         helper(nums, memo, start+1);
//         memo.pop_back();
//     } else {
//         int cur = memo.back();
//         if (nums[i]%cur==0) {
//             memo.push_back(nums[i]);
//             helper(nums, memo, start+1);
//             memo.pop_back();
//         }
//     }
// }



class Solution {
public:
    vector<int> ans;    
    vector<int> dp;
    
    void helper(vector<int>& nums,vector<int> &memo, int start) {
        if (start==nums.size()) {
            if (memo.size()>ans.size()) {
                ans=memo;
            }
            return;
        }
        
        // 这种带条件的不太好用for loop，换这种
        // 不要使用返回vector的做法看看
        // 即正向来看，如何剪枝
        // 1 3 4 6 12 => 1 4 12 也可以 1 3 6 12， 那么显然选择后者，同样是12， 对后面来说没有差别
        if (memo.empty()) {
            memo.push_back(nums[start]);
            helper(nums, memo, start+1);
            memo.pop_back();
        } else if (int(memo.size())>dp[start] && nums[start] % memo.back() == 0) {
            dp[start]=memo.size();
            memo.push_back(nums[start]);
            helper(nums, memo, start+1);
            memo.pop_back();
        }
        // not divisable, skip it
        helper(nums, memo, start+1);
    }


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> memo;
        dp.resize(n,-1);
        helper(nums, memo, 0);        
        return ans;
    }
};