//
// Created by rui zhou on 07/05/19.
//

//LC 572

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        bool isSubtree(TreeNode *t1,TreeNode*t2) {
            return helper(t1,t2) || (t1 &&
                    (isSubtree(t1->left,t2) ||
                            isSubtree(t1->right,t2))) ||
                    (t1==nullptr && t2==nullptr);
        }


        bool helper(TreeNode*t1,TreeNode*t2) {
            if (t1&&t2) {
                return (t1->val==t2->val) &&
                        helper(t1->left,t2->left) &&
                        helper(t1->right,t2->right);
            } else {
                return t1==nullptr && t2==nullptr;
            }
        }
    };
}