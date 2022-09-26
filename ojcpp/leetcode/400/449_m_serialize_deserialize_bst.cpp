//
// Created by rui zhou on 14/03/19.
//

/* amazon
 * Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored
 * in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or
 * another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your
 serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized
 to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should
 be stateless.
 */

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace lc449 {
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
    class Codec {
    public:

        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            std::deque<TreeNode*> deq{root};
            std::stringstream ss;
            while (!deq.empty()) {
                auto node=deq.front();
                deq.pop_front();
                if (node) {
                    ss<<node->val;
                    deq.emplace_back(node->left);
                    deq.emplace_back(node->right);
                } else {
                    ss<<"na";
                }

                if (!deq.empty()) {
                    ss<<",";
                }
            }
            return ss.str();
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            stringstream ss(data);
            string tmp;
            TreeNode dummy(0);
            TreeNode *parent=&dummy;
            std::deque<TreeNode*> toDo{parent};
            int idx=0;
            size_t sz;


            while (getline(ss,tmp,',')) {
                if (!toDo.empty()) {
                    parent = toDo.front();
                } else {
                    break;
                }

                TreeNode*child = nullptr;
                if (tmp!="na") {
                    int val=stoi(tmp,&sz,10);
                    child = new TreeNode(val);
                } else {
                    child = nullptr;
                }

                if (idx%2==1) {
                    parent->left=child;
                    if (child)
                        toDo.push_back(child);
                }
                if (idx%2==0) {
                    parent->right=child;
                    if (child)
                        toDo.push_back(child);
                    toDo.pop_front();
                }
                idx++;
            }
            return dummy.right;
        }
    };

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
}

DEFINE_CODE_TEST(449_serialize_bst)
{
    lc449::Codec obj;
    {
        TreeNode *root=LCREATE_TREENODE({5,4,6,3,null,null,8,null,null,null,null});
        string s = obj.serialize(root);
        cout <<s <<endl;
        TreeNode *dnode=obj.deserialize(s);
        cout <<TREE_PREORDER(dnode) <<endl;

    }

}