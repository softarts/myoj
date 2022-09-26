//
// Created by rui.zhou on 3/6/2019.
//

//参见LC 105, build from pre-order and in-order
//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]

// pre-order = {1,2,4,7,3,5,6,8}
// in-order = {4,7,2,1,5,3,8,6}

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace {
    class Solution {
    public:
        TreeNode* helper(unordered_map<int,int> &map,vector<int>& pre, vector<int>& in, int i,
                int start, int end) {
            if (start==end) // null area
                return nullptr;

            TreeNode *root = new TreeNode(pre[i]);
            int inPos=map[pre[i]];
            root->left = helper(map,pre,in, i+1, start, inPos);  // left size=start~inPos
            root->right = helper(map,pre,in,i+1+inPos-start,inPos+1,end);//in start= right root
            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int,int> map;
            for (int i=0;i<inorder.size();i++) {
                map[inorder[i]] = i;
            }
            return helper(map,preorder,inorder,0,0,inorder.size());
        }
    };
}

DEFINE_CODE_TEST(hht_006_rebuild_bintree)
{
    Solution obj;
    {
        vector<int> p{1,2},i{1,2};
        VERIFY_CASE(TREE_PREORDER(obj.buildTree(p,i)),"1 2");
    }

}