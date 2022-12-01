/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "common.h"
#include <vector>
/*
DFS可以得到各个点的高度，但是题目的输入是一个数组，所以如何避免重复计算
初始化时一次过计算,由于每个点的数值唯一，所以可以用hashmap保存
每个点都保存一个替代节点的最大值,4保存的是3的高度

1. 首先得到每个点所具备的max高度(每棵子树的高度height)，最上面的高度为最大，最底层的高度为1
对于root， 替换的话高度显然就是0

很精彩的一道题，特别是第二次递归
*/
#include <unordered_map>
using namespace std;

class Solution {
public:    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<TreeNode*,int> height;
        function<int(TreeNode*)> getHeight = [&](TreeNode *node){
            if (node) {
                height[node]=1+max(getHeight(node->left), getHeight(node->right));
                return height[node];
            } else {
                return 0;
            }
        };
        getHeight(root);
        unordered_map<int,int> ans;

        function<void(TreeNode*,int,int)> getAns = [&](TreeNode*node, int depth, int restH) {
            if (node==nullptr) return;
            // 删除当前节点所得到的剩余子树的最大高度
            ans[node->val] = restH;
            ++depth;
            // 递归到下一层子树，depth+1,
            // 从根节点到当前节点深度(depth)+到当前节点右子树最深节点的长度
            // 删除当前节点子树后的最大深度，取最大值
            // 原因是以上可能是两条不同的路径: 1-3-2; 和1-4-5-7
            getAns(node->left,depth,max(restH,depth+height[node->right]));
            getAns(node->right,depth,max(restH,depth+height[node->left]));
        };
        getAns(root, -1, 0);
        for (auto &q:queries) {
            q = ans[q];
        } 
        return queries;
    }
};