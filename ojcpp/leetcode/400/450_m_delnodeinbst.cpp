//
// Created by Rui Zhou on 27/3/18.
//

/*
 * https://leetcode.com/problems/delete-node-in-a-bst/description/
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

 root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
#include <codech/algo_common.h>

using namespace CODECH;

namespace {
    class Solution0 {
    public:
        // from introduction to algo, slow....
        TreeNode * root_;
        TreeNode* deleteNode0(TreeNode* root, int key) {
            root_ = root;
            TreeNode *cur = root;
            TreeNode *pre = nullptr;
            while (cur!=nullptr && cur->val!=key) {
                pre = cur;
                if (key < cur->val) {
                    cur = cur->left;
                } else if (key > cur->val) {
                    cur = cur->right;
                }
            }
            deleteTreeNode(pre, cur);
            return root_;
        }

        void transplant(TreeNode *parent, TreeNode*delNode,TreeNode *newNode) {
            if (parent == nullptr) {
                root_ = newNode;
            } else if (parent->left == delNode) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }

        void deleteTreeNode(TreeNode *parent, TreeNode *delNode) {
            if (delNode == nullptr)
                return;
            if (delNode->left == nullptr) {
                transplant(parent, delNode, delNode->right);
            } else if (delNode->right == nullptr) {
                transplant(parent, delNode, delNode->left);
            } else {
                // find minimum in right subtree
                TreeNode* next = delNode->right;
                TreeNode* pre = delNode;
                for(; next->left != nullptr; pre = next, next = next->left);

                if (pre != delNode) {
                    transplant(pre, next, next->right);
                    next->right = delNode->right;
                }
                transplant(parent, delNode, next);
                next->left = delNode->left;
            }
        }

        // -----------------------------
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (!root)
                return nullptr;
            if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else if (key > root->val) {
                root->right = deleteNode(root->right, key);
            } else { // find the node
                if (!root->left) {
                    return root->right;
                } else if (!root->right) {
                    return root->left;
                } else {
                    // find the minimum successor in right tree
                    TreeNode *next = root->right;
                    while (next->left) {
                        next = next->left;
                    }
                    root->val = next->val;
                    root->right = deleteNode(root->right, root->val);
                }
            }
            return root;
        }
    };

    class Solution {
    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root== nullptr) {
                return nullptr;
            }
            if (root->val == key) {
                TreeNode *left = root->left;
                TreeNode *right = root->right;

                if (left==nullptr) {
                    return right;
                } else if (right == nullptr) {
                    return left;
                }
                TreeNode *p=root->right;

                while (p->left) {
                    p = p->left;
                }
                p->left = left;
                return right;
            } else {
                if (root->val > key) {
                    root->left = deleteNode(root->left, key);
                } else if (root->val < key) {
                    root->right = deleteNode(root->right, key);
                }
                return root;
            }
        }
    };
}


DEFINE_CODE_TEST(450_delnodeinbst)
{
    Solution obj;
    {
        TreeNode *root = LCREATE_TREENODE({2,0,33,null,1,25,40,null,null,11,31,34,45,10,18,29,32,null,36,43,46,4,null,12,24,26,30,null,null,35,39,42,44,null,48,3,9,null,14,22,null,null,27,null,null,null,null,38,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,37,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,null,null,7,null,16,null,null,20,6});
        //TREE_BYLEVEL(root);
        VERIFY_CASE(TREE_BYLEVEL(obj.deleteNode(root, 33)),"2,0,34,null,1,25,40,null,null,11,31,36,45,10,18,29,32,35,39,43,46,4,null,12,24,26,30,null,null,null,null,38,null,42,44,null,48,3,9,null,14,22,null,null,27,null,null,37,null,41,null,null,null,47,49,null,null,5,null,13,15,21,23,null,28,null,null,null,null,null,null,null,null,null,8,null,null,null,17,19,null,null,null,null,null,7,null,16,null,null,20,null,null,null,null,null,null,");
    }
    /*
    {
        TreeNode *root = CREATE_TREENODE(0,{5,3,6,2,4,null,7});
        TREE_PREORDER(obj.deleteNode(root, 3));
    }*/

}