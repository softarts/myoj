//
// Created by rui zhou on 09/05/19.
//

#include <codech/codech_def.h>

using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root) return 0;
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            return max(leftDepth+1, rightDepth+1);
        }
    };
}

DEFINE_CODE_TEST(hht_104_maxdepthtree)
{
    Solution obj;
    {
        TreeNode *root = CODECH::CREATE_TREENODE({3, 9, 20, null, null, 15, 7});
        VERIFY_CASE(obj.maxDepth(root),3);
    }
}

