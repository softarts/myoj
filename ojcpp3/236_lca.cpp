#include <iostream>
#include "common.h"
using namespace std;

/*
binary tree, 给出两个node，找出其最小的公共祖先
常见考题.既存在某个节点，p q都是其child
递归的做法，对每一个node，都调用left,right=lowestCommonAncestor()
树经常是一些递归的做法
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root ==nullptr || root==p || root=q) {
            return root;
        }
        auto left=lowestCommonAncestor(root->left, p, q);
        auto right=lowestCommonAncestor(root->left, p, q);

        if (left==nullptr) {
            return right;
        } else if (right==nullptr) {
            return left;
        } else {
            return root;// left和right都不为空，说明root就是其pparent
        }

    }
};

int main() {
    return 0;
}