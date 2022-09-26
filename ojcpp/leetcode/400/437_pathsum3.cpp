//
// Created by rui zhou on 01/05/19.
//

/*
 * https://leetcode.com/problems/path-sum-iii/
 * You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,0000 nodes and the values are in the range -1,0000,0000 to 1,0000,0000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace {
    class Solution {
    public:

        int pathSum(TreeNode* root, int sum) {
            if (!root)
                return 0;
            return sumUp(root, 0, sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
        }


        int sumUp(TreeNode *node,int pre, int target) {
            if (!node)
                return 0;
            int current = pre + node->val;
            return (current==target) + sumUp(node->left, current, target) + sumUp(node->right,current, target);
        }
    };
}


DEFINE_CODE_TEST(437_pathsum3)
{
    Solution obj;
    {
        TreeNode *root = CREATE_TREENODE({10,5,-3,3,2,null,11,3,-2,null,1});
        VERIFY_CASE(obj.pathSum(root,8), 3);
    }

}