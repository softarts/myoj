#include "common.h"
#include <iostream>
using namespace std;

//因为保证node在tree中，所以不用考虑是否root==null
// 退出条件是=p || =q
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==p || root==q){
            return root;
        }
        
        if ((p->val < root->val && root->val < q->val) || (p->val > root->val && root->val > q->val)){
            return root;
        } else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left,p,q);
        } else {
            return lowestCommonAncestor(root->right,p,q);
        }
    }
};