#include <vector>
#include "common.h"
#include <stack>
#include <deque>
using namespace std;
//从下往上，按层遍历
// 原解法用递归，符合bottom-up的思路，服了
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<vector<int>> st;
        deque<TreeNode*> dq{root};
        while (!dq.empty()) {
            vector<int> layer;
            size_t n = dq.size();
            for (int i=0;i<n;i++) {
                auto node = dq.front();
                dq.pop_front();
                layer.emplace_back(node->val);
                if (node->left) dq.emplace_back(node->left);
                if (node->right) dq.emplace_back(node->right); 
            }
            st.push_front(layer);
        }
        return vector<vector<int>>(st.begin(),st.end());
     }
};