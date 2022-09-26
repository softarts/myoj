#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

// 这个代码更漂亮
namespace {
    class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            if (root==nullptr) return vector<int>();
            deque<TreeNode*> deq{root};
            vector<int> ans{root->val};
            while (!deq.empty()) {
                vector<TreeNode*> tmp;
                while (!deq.empty()) {
                    TreeNode *node=deq.front();
                    deq.pop_front();
                    if (node->left) {
                        tmp.push_back(node->left);
                    }
                    if (node->right) {
                        tmp.push_back(node->right);
                    }
                } 
                //自定义comp               
                auto iter = max_element(tmp.begin(),tmp.end(),[](const auto *a,const auto *b){return a->val<b->val;});
                if (iter!=tmp.end()) ans.push_back((*iter)->val);
                deq.insert(deq.end(),tmp.begin(),tmp.end());
            }
            return ans;
        }
    };
}