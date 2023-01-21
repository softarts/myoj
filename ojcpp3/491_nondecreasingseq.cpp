#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

/*
Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
6:20PM
backtracking?
*/
class Solution {
public:
    // unordered_set 不支持 vector<int> 作为T
    // set可以
    set<vector<int>> ans;
    vector<vector<int>> ret;


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> memo;
        helper(memo, nums, 0);    
        return vector<vector<int>>(ans.begin(),ans.end());
    }

    // 这个来描述take or not take比较适当，但缺点就是会重复取数字
    void helper(vector<int> &memo, vector<int>& nums, int start) {
        if (start>=nums.size()) {
            if (memo.size()>=2) {
                //ans.push_back(memo);                
                ans.insert(memo);                
            }
            return;
        }

        if ((!memo.empty() && memo.back()<=nums[start]) || memo.empty()) {
            memo.push_back(nums[start]);
            helper(memo, nums, start+1);
            memo.pop_back();
        }
        // donot take it
        helper(memo, nums, start+1);
    }
};