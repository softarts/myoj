//
// Created by rui.zhou on 3/5/2019.
//

//参见leetcode 046 permutation, 031

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ret;
            helper(nums, ret,0,nums.size());
            return ret;
        }

        void helper(vector<int> comb,vector<vector<int>> &ret,int start,int end) {
            if (start==end) {
                ret.emplace_back(comb);
                return;
            }

            for (int i=start;i<end;i++) {
                swap(comb[start],comb[i]);
                helper(comb,ret,start+1,end);
            }
        }
    };
}