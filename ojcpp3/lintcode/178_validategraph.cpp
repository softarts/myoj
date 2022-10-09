#include <vector>
using namespace std;

/*
给出 n 个节点，标号分别从 0 到 n - 1 并且给出一个 无向 边的列表 (给出每条边的两个顶点), 写一个函数去判断这张｀无向｀图是否是一棵树
输入: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
输出: true.
11:31 ->
有点难绷，不知道如何解决来回引用的问题
1. 采用pre
2. union find?
*/
// lc261 medium
#include <iostream>

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {  

        vector<int> roots(n,-1);
        for (auto &iter:edges) {
            int r0 = findRoots(iter[0],roots);
            int r1 = findRoots(iter[1],roots);
            if (r0!=r1) {
                roots[r0] = r1;
            } else {
                return false;
            }
        }
        return edges.size() == n - 1;
    }

    int findRoots(int node, vector<int> &roots) {
        while (roots[node]!=-1) {
            node=roots[node];
        }
        return node;
    }
};


int main() {
    Solution obj;
    {
        vector<vector<int>> edges={{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
        bool actual=obj.findRoots(5,edges);
        cout << boolalpha << (actual==false) << endl;
    }
    return 0;
}