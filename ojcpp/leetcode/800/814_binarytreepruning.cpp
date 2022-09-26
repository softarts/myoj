//
// Created by rui zhou on 08/04/18.
//


/*
 * remove leaf which is 0
 */


#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return dfs(root);
    }

    TreeNode* dfs(TreeNode* node) {
        if (!node) {
            return node;
        }

        node->left = dfs(node->left);
        node->right = dfs(node->right);

        if (!node->left && !node->right) {
            if (node->val == 0) {
                return nullptr;
            }
        }
        return node;
    }
};



DEFINE_CODE_TEST(814_binary_tree_pruning)
{
    Solution obj;
    {
        TreeNode *root = LCREATE_TREENODE({1,null,0,0,1,null,null,null,null});
        root = obj.pruneTree(root);
        TREE_PREORDER(root);
        cout<<endl;
    }
    {
        TreeNode *root = LCREATE_TREENODE({1,0,1,0,0,0,1,null,null,null,null,null,null,null,null});
        root = obj.pruneTree(root);
        TREE_PREORDER(root);
        cout<<endl;
    }

}