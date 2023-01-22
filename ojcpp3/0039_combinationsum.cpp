#include <vector>
#include <algorithm>

using namespace std;
/*
[2 3 6 7] ==>7,output [2,2,3] [7]
基本上是深度搜索
先排序
backtrace的一个变种
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());      
        vector<vector<int>> ans;
        vector<int> comb;
        helper(0,target,candidates,comb,ans);
        return ans;
    }


    void helper(int start,int target, vector<int>& arr, vector<int> &comb, vector<vector<int>> &ans) {
        if (target==0) {
            ans.push_back(comb);
            return;
        }

        for (int i=start;i<arr.size() && target>=arr[i];i++) {
            comb.emplace_back(arr[i]);
            helper(i,target-arr[i],arr,comb,ans);
            comb.pop_back();
        }
    }
};