//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

 it is not search bintree
 convert to linkedlist
思路， 并非BST，将其转化为链表，然后求链表的公共点
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
#include <list>

using namespace CODECH;
using namespace std;

class Solution {
public:
    bool treeToList(TreeNode*cur, TreeNode*p, list<TreeNode*> &lst) {
        if (cur==nullptr) {
            return false;
        } else if (cur == p) {
            lst.push_back(cur);
            return true;
        }
        lst.push_back(cur);
        bool ret = treeToList(cur->left, p, lst);
        if (ret) {
            return true;
        }

        ret = treeToList(cur->right, p, lst);
        if (ret) {
            return true;
        } else {
            lst.pop_back();
            return false;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode*> pl;
        bool pb = treeToList(root, p, pl);
        list<TreeNode*> pq;
        bool qb = treeToList(root, q, pq);

        if (pb) {
            for (auto &iter:pl) {
                cout << iter << ":" << iter->val << " --> ";
            }
            cout << endl;
        }

        if (qb) {
            for (auto &iter:pq) {
                cout << iter << ":" << iter->val << " --> ";
            }
            cout << endl;
        }
        auto cur1 = pl.rbegin();
        auto cur2 = pq.rbegin();


        while ((*cur1)!=(*cur2)) {
            if (++cur1 == pl.rend()) {
                cur1 = pq.rbegin();
            }
            if (++cur2 == pq.rend()) {
                cur2 = pl.rbegin();
            }
        }
        return (*cur1);
    }
    //这个解法很精彩
    class Solution1 {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root==nullptr || root==p || root==q) {
                return root;//found it
            }
            TreeNode *left=lowestCommonAncestor(root->left, p, q);
            TreeNode *right=lowestCommonAncestor(root->right, p, q);
            if (left==nullptr) {
                return right;// both must be right, and the right is the parent
            } else if (right==nullptr) {
                return left;
            } else {
                return root;//one left,one right
            }
        }
    };



};


DEFINE_CODE_TEST(236_lowestcommonnode)
{
    //TODO
//    Solution obj;
//    {
//        TreeNode *root = CREATE_TREENODE(0,{37,-34,-48,0,-100,-101,48,0,0,0,0,-54,0,-71,-22});
//        TreeNode*p = FIND_NODE(root, -100);
//        TreeNode*q = FIND_NODE(root, -101);
//        VERIFY_CASE(obj.lowestCommonAncestor(root, p, q), root);
//    }
//
//    {
//        TreeNode *root = CREATE_TREENODE(0,{3,5,1,6,2,10,8,0,0,7,4,0,0,0,0});
//        TreeNode*p = FIND_NODE(root, 5);
//        TreeNode*q = FIND_NODE(root, 1);
//        VERIFY_CASE(obj.lowestCommonAncestor(root, p, q), root);
//    }

}