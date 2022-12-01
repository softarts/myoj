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

/*
妈呀这居然能直接AC
*/
#include "../common.h"
using namespace std;

class Solution {
public:
    int ans=0;
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }


    int helper(TreeNode *node) {
        if (node==nullptr) return 0;

        int left = helper(node->left);
        int right = helper(node->right);
        
        if (node->left && node->left->val == node->val) {
            left=left+1;
        } else {
            left = 0;
        }

        if (node->right && node->right->val == node->val) {
            right=right+1;
        } else {
            right = 0;
        }
        ans = max(ans,left+right);
        return max(left,right);
    }
};