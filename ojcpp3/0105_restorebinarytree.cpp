#include "../common.h"
#include <vector>
using namespace std;

/**
 medium only
 TODO 总结
 
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder); 
    }

    pair<vector<int>,vector<int>> getNewInorder(int parent, vector<int> inorder) {
        auto parentPos = find(inorder.begin(), inorder.end(), parent);
        return pair(
            vector<int>(inorder.begin(),parentPos),
            vector<int>(parentPos+1,inorder.end())
        );
    }

    TreeNode* createTree(vector<int> preorder, vector<int> inorder) {
        if (preorder.empty()) return nullptr;
        auto parent=preorder[0];        
        auto [leftInorder,rightInorder]= getNewInorder(parent, inorder);
        int lsz = leftInorder.size();
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+1+lsz);
        vector<int> rightPreorder(preorder.begin()+1+lsz, preorder.end());        
        TreeNode *node = new TreeNode(parent);
        node->left=createTree(leftPreorder, leftInorder);
        node->right=createTree(rightPreorder, rightInorder);
        return node;
    }
};