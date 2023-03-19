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
bst的话, 第k节点必然是左边子树有k-1个节点*/
#include "../common.h"
using namespace std;

class Solution {
public:
    int n;
    bool stop = false;
    int ans;
    int kthSmallest(TreeNode* root, int k) {
        n=k;  
        helper(root);
        return ans;  
    }

    void helper(TreeNode *node) {
        if (node==nullptr || stop) {
            return;
        }
        helper(node->left);
        if (--n==0) {
            stop=true;
            ans = node->val;
            return;
        }
        helper(node->right);
    } 
    // 此方法完全错误,并不是光看left的数目
    // int helper(TreeNode *node) {
    //     if (node==nullptr) return 0;
    //     if (stop) return 0;
    //     int left = helper(node->left);
    //     if (left==n-1) {
    //         stop = true;
    //         ans = node->val;
    //     }
    //     int right = helper(node->right);
    //     return left+1+right;
    // }
};