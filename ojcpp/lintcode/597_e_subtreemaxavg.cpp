//
// Created by rui zhou on 27/02/19.
//

/* amazon
 * https://www.lintcode.com/problem/subtree-with-maximum-average/description
 * Given a binary tree, find the subtree with maximum average. Return the root of the subtree.

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with maximum average.

Have you met this question in a real interview?
Example
Example 1

Input：
     1
   /   \
 -5     11
 / \   /  \
1   2 4    -2
Output：11(it's a TreeNode)
Example 2

Input：
     1
   /   \
 -5     11
Output：11(it's a TreeNode)
Related Problems

 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the root of the maximum average of subtree
     */
    TreeNode *findSubtree2(TreeNode *root) {
        // Write your code here
        /*thesize=1;
        thesum=INT_MIN;
        thenode=nullptr;*/
        helper(root);
        return thenode;
    }

    pair<int,int> helper(TreeNode *node) {
        if (!node)
            return {0,0};
        auto left = helper(node->left);
        auto right = helper(node->right);
        int size=1+left.second+right.second;
        int sum=node->val+left.first+right.first;
        if ((double)sum/size > (double)thesum/thesize) {
            thesum=sum;thesize=size;thenode=node;
        }
        return {sum,size};
    }

    int thesize=1;
    int thesum=INT_MIN;
    TreeNode*thenode=nullptr;

};

DEFINE_CODE_TEST(lint_597_subtreemaxavg)
{
    Solution obj;
    {
        vector<int> nums{1,-5,11,1,2,4,-2};
        TreeNode *root=LCREATE_TREENODE(nums);
        TreeNode *node=obj.findSubtree2(root);
        VERIFY_CASE(node->val,11);
    }

}