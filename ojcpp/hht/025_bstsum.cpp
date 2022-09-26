//
// Created by rui.zhou on 2/10/2019.
//

/*
 * 二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 class Node:
    def __init__(self, val):
        print "create node, val=",val
        self.left = None
        self.right = None
        self.data = val


def create_node(idx, lst):
    if idx<len(lst):
        val = lst[idx]
        if val > 0:
            node = Node(lst[idx])
            node.left = create_node(idx*2+1, lst)
            node.right = create_node(idx*2+2, lst)
            return node
        return None
    else:
        return None


def pre_order(root):
    print root.data,
    if root.left:
        pre_order(root.left)
    if root.right:
        pre_order(root.right)


def create_tree():
    lst = [10, 5, 12, 4, 7, 0, 0]
    root = create_node(0, lst)
    pre_order(root)
    return root


def find_path(root, path,  val):
    if val == sum(path) + root.data:
        # path.append(root.data)
        print "found:", path, root.data
        return True
    else:
        ret = False
        path.append(root.data)
        if root.left:
            ret = find_path(root.left, path, val)

        if root.right:
            ret = find_path(root.right, path, val)

        del path[-1]
        return ret
    pass

def sum_bst():
    root = create_tree()
    print ""
    path=[]
    find_path(root, path, 22)

if __name__ == '__main__':
    sum_bst()
 */

#include <codech/codech_def.h>
#include <numeric>
using namespace CODECH;
using namespace std;

//backtracking
namespace HHT {
    class Solution {
    public:
        void find_path(TreeNode*root, int target) {
            vector<int> path;
            return helper(root, path, target);
        }

        void print_path(vector<int> &path, int val) {
            cout << "FOUND:";
            for (auto &el : path) {
                cout << el << " ";
            }
            cout << val << endl;
        }

        void helper(TreeNode *root, vector<int> &path, int target) {
            if (!root)
                return;
            if (accumulate(path.begin(),path.end(),0)+root->val == target) {
                print_path(path, root->val);
            }
            path.push_back(root->val);
            helper(root->left,path,target);
            helper(root->right,path,target);
            path.pop_back();
        }
    };
}

using namespace HHT;
DEFINE_CODE_TEST(HHT_025_bstsum)
{
    Solution obj;
    {
        vector<int> nums{10,5,12,4,7};
        TreeNode*root = LCREATE_TREENODE(nums);
        obj.find_path(root,22);
        //VERIFY_CASE(obj.isValidSudoku(board),true);
    }

}