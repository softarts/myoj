/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "common.h"
#include <vector>
#include <unordered_set>
using namespace std;
/*
返回从root到叶节点 的sum=target的所有节点
应该是常见的考题，dfs
这里用上unordered_set<vector<int>> ans; 却有问题，因为没有定义hash of vector<int>
需要修改下在上一级就判断，不要留到下一级，否则造成重复结果
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> comb;
        helper(root,comb,targetSum);
        return ans;
    }

    void helper(TreeNode *node,vector<int>&comb, int target) {
        if (node==nullptr) return;
        comb.push_back(node->val);
        if (node->left==nullptr && node->right==nullptr && target==node->val) {
            ans.push_back(comb);
        } else {
            helper(node->left,comb,target-node->val);
            helper(node->right,comb,target-node->val);
        }
        comb.pop_back();
    }
};