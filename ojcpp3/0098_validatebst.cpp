#include "common.h"
#include <climits>
using namespace std;

// 验证二叉搜索树的思路
// 左子树小于node,右子树大于node,但是还要保证右子树的最小值必须大于node,左子树的最大值必须小于node
// 即每个递归的时候把最大最小值传递进去
// 考虑有些节点用了非常大的数值
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long minv = LONG_MIN;
        long maxv = LONG_MAX;
        return helper(root, minv, maxv);
    }
    bool helper(TreeNode *node, long minv, long maxv) {
        if (!node) return true;
        return (
            node->val>minv &&
            node->val<maxv &&
            helper(node->left, minv, node->val) &&
            helper(node->right, node->val, maxv)
        );
    }
};

int main() {
    return 0;
}