//
// Created by rui.zhou on 2019/12/17.
//
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
/*
因为保证node在tree中，所以不用考虑是否root==null
*/

namespace {
    // 查找节点的公共节点
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
}