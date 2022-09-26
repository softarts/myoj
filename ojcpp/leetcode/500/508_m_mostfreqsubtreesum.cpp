#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;

namespace {
    class Solution {
    public:
        unordered_map<int,int> m;
        int maxCount=0;
        vector<int> findFrequentTreeSum(TreeNode* root) {
            helper(root);
            vector<int> ans;
            for (auto &it:m) {
                if (it.second==maxCount) {
                    ans.push_back(it.first);
                }
            }
            return ans;
        }
        
        int helper(TreeNode*root) {
            if (root==nullptr) return 0;
            int left=helper(root->left);
            int right=helper(root->right);
            int sum = root->val+left+right;
            m[sum]+=1;
            maxCount = max(maxCount,m[sum]);
            return sum;
        }
    };
}