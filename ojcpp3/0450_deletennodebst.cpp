#include "../common.h"

/*
删除一个bst的节点
按照codesignal的做法，把左节点的最右节点提到root
比lc的要求难
*/
using namespace std;
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode **pnode = &root;
        while (*pnode && (*pnode)->val!=key) {
            if ((*pnode)->val>key) {
                pnode=&(*pnode)->left; // 改变指针的指向，而不是指针的值
            } else if ((*pnode)->val<key) {
                pnode=&(*pnode)->right;
            }
        }
        // pnode = the node to be deleted
        // pnode is null or val=key

        if (*pnode) {
            
            if ((*pnode)->left) {
                TreeNode **pRightMost = &(*pnode)->left;
                // find the rightmost node of left tree.
                while ((*pRightMost)->right) {
                    pRightMost = &(*pRightMost)->right;
                }
                TreeNode* lastLeft = (*pRightMost)->left;
                if (*pRightMost != (*pnode)->left) {
                    (*pRightMost)->left = (*pnode)->left; // 左子树为原左子树
                }
                (*pRightMost)->right = (*pnode)->right;
                *pnode = *pRightMost;
                *pRightMost = lastLeft;
            } else {
                *pnode = (*pnode)->right;
            }
        }
        return root;
    }
};