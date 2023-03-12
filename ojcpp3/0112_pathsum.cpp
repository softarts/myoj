#include "common.h"
#include <iostream>
using namespace std;

// 求root到leaf的sum=target 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) {
            return false;
        }
        
        return (root->left==nullptr && root->right==nullptr && root->val==targetSum)
                || hasPathSum(root->left, targetSum-root->val) 
                || hasPathSum(root->right, targetSum-root->val);
    }
};