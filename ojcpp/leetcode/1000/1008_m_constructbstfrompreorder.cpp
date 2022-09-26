//
// Created by rui.zhou on 3/10/2019.
//
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace c127bst {
    class Solution {
    public:
        TreeNode* bstFromPreorder(vector<int>& preorder) {
            return dfs(preorder);
        }

        TreeNode *dfs(vector<int> &preorder) {
            if (preorder.empty())
                return nullptr;

            int rootVal=preorder[0];
            TreeNode *root = new TreeNode(rootVal);

            int rightIdx=-1;
            for (int i=0;i<preorder.size();i++) {
                if (preorder[i]>rootVal) {
                    rightIdx=i;
                    break;
                }
            }

            int rightSize=0;
            if (rightIdx!=-1) {
                vector<int> pright(preorder.begin()+rightIdx,preorder.end());
                rightSize=pright.size();
                root->right=dfs(pright);
            }

            if (preorder.size()-1-rightSize>0) {
                vector<int> pleft(preorder.begin()+1,preorder.begin()+preorder.size()-rightSize);
                root->left=dfs(pleft);
            }
            return root;
        }

    };
}

DEFINE_CODE_TEST(1008_maketreefrompreorder) {
    c127bst::Solution obj;
    {
        vector<int> p{4,2};
        VERIFY_CASE(TREE_PREORDER(obj.bstFromPreorder(p)),"4 2");

    }
    {
        vector<int> p{8,5,1,7,10,12};
        VERIFY_CASE(TREE_PREORDER(obj.bstFromPreorder(p)),"8 5 1 7 10 12");

        //Input: [8,5,1,7,10,12]
        //Output: [8,5,10,1,7,null,12]
    }

}