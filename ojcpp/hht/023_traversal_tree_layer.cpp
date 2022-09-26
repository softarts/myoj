//
// Created by rui.zhou on 5/9/2019.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

namespace {
    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> ret;
            deque<TreeNode*> dq{root};
            int count=1;
            while (!dq.empty()) {
                vector<int> level;
                int levelCount = 0;
                for (int i=0;i<count;i++) {
                    TreeNode *node = dq.front();
                    dq.pop_front();
                    if (node) {
                        level.emplace_back(node->val);
                        dq.push_back(node->left);
                        dq.push_back(node->right);
                        levelCount +=2;
                    }
                }
                if (!level.empty()) {
                    ret.emplace_back(level);
                }
                count = levelCount;
            }
            return ret;
        }
    };
}