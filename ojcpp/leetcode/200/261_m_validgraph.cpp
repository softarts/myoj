#include <codech/codech_def.h>
using namespace std;

/*
lc261 lock
lintcode 178
https://www.lintcode.com/problem/178/
描述
给出 n 个节点，标号分别从 0 到 n - 1 并且给出一个 无向 边的列表 (给出每条边的两个顶点), 写一个函数去判断这张｀无向｀图是否是一棵树

假设列表中没有重复的边。 无向边　[0, 1] 和 [1, 0]　是同一条边， 因此它们不会出现在列表中。

样例
样例 1:

输入: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
输出: true.
样例 2:

输入: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
输出: false.

思路
1.树的话必须无环
2.必须链接在一起，只有一个group
3.应为无向图，否则无法判断是否造成闭环

无向图:
否则无法判断是否造成闭环,但是怎么从一个点出发能够确保遍历所有节点？

双向图:
如果需要从一个点出发，在一个dfs里判断是否所有的点都连接在一起，那么必须用双向图,但是闭环？

参考547如何寻找所有链接点
// 应参考310 的做法，tree的话必须满足去掉所有只有一个edge的点后，最后q中只剩下一个节点
正确解法-并查集
*/

namespace {
//    class Solution {
//     public:
//         /**
//          * @param n: An integer
//          * @param edges: a list of undirected edges
//          * @return: true if it's a valid tree, or false
//          */
//         unordered_map<int, forward_list<int>> m;
//         bool validTree(int n, vector<vector<int>> &edges) {
//             // write your code here
//             for (auto &v:edges) {
//                 m[v[0]].push_front(v[1]);
//                 // m[v[1]].push_back(v[0]);
//             }
//             //vector<bool> visited(n,false);
//             unordered_set<int> visited;
//             for (int i=0;i<n;i++) {
//                 cout<<"start "<<i<<endl;
//                 if (!traverse(i,visited)) {
//                     return false;
//                 }
//             }
//             cout << visited.size()<<endl;
//             return visited.size()==n;
//         }


//         bool traverse(int node, unordered_set<int> &visited) {
//             if (visited.count(node)) {
//                 cout <<"visited again " << node;
//                 return false;
//             }
//             cout <<"visited " << node <<endl;
//             visited.insert(node);

//             for (auto &v:m[node]) {
//                 if (!traverse(v,visited)) {
//                     return false;
//                 }
//             }
//             //visited[node]=false;
//             return true;
//         }
//     }; 

    // class Solution {
    //     public:
    //     unordered_map<int, unordered_set<int>> m;
    //     bool validTree(int n, vector<vector<int>> &edges) {
    //         for (auto &v:edges) {
    //             m[v[0]].insert(v[1]);
    //             m[v[1]].insert(v[0]);
    //         }

    //         for (int i=0;i<n;i++) {
    //             m[i].insert(i);
    //         }

    //         dfs(0);
                
    //         if (m.empty()) {
    //             return true;
    //         } else {
    //             return false;
    //         }
    //     }

    //     void dfs(int origin) {
    //         while (!m[origin].empty()) {
    //             auto nextIt = m[origin].begin();
    //             auto next=*nextIt;
    //             m[origin].erase(nextIt);
    //             if (origin!=next) {
    //                 dfs(next);
    //             }
    //         }
    //         m.erase(origin);

    //     }
    // };

    
    // 这道题从图遍历怎么都不方便，并查集

    class Solution {
    public:        
        bool validTree(int n, vector<vector<int>> &edges) {
            if (edges.size()+1!=n) return false; //边的个数必须比n少1
            vector<int> parent(n,-1);
            for (int i=0;i<n;i++) {
                parent[i]=i;
            }

            for (auto &v:edges) {
                int p0=v[0];
                int p1=v[1];
                while (p0!=parent[p0]) {
                    p0=parent[p0];
                }
                while (p1!=parent[p1]) {
                    p1=parent[p1];
                }
                if (p0!=p1) {  // 两个属于不同的父节点
                    parent[p0]=p1;
                } else { //两个属于同一个父节点，而且这个还有edge，说明是个环
                    return false;
                }
            }
            return true;
        }
    };


}