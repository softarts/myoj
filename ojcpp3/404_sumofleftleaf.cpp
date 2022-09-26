#include "common.h"
#include <deque>
using namespace std;

// layer
// 递归使用flag标记也不错
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        deque<TreeNode*> deq{root};
        int sum = 0;
        while (!deq.empty()) {
            //vector<TreeNode *> layerNodes;
            size_t n=deq.size();
            for (int i=0;i<n;i++) {
                auto node = deq.front();
                deq.pop_front();
                if (node!=nullptr) {
                    deq.push_back(node->left);
                    deq.push_back(node->right);
                    if (node->left==nullptr && node->right==nullptr && i%2==0 && node!=root) {
                        sum+=node->val;
                    }
                }
            }
        }
        return sum;
    }
    
        
};
