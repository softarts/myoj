//
// Created by rui.zhou on 3/28/2019.
//

/*
 * Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace {
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
        TreeNode* invertTree(TreeNode* root) {
            if (!root)
                return root;
            invertTree(root->left);
            invertTree(root->right);
            TreeNode *tmp=root->left;
            root->left=root->right;
            root->right=tmp;
            return root;
        }
    };
}

DEFINE_CODE_TEST(226_invert_binary_tree)
{

}