/*
Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
给出一个matrix,1表示相连，指同属一个province
找出有几个province

//algorithm 40
使用并查集的做法更好，不需要dfs
这个题目挺值得练习
*/
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // int findCircleNum_bad(vector<vector<int>>& isConnected) {
    //     unordered_set<int> ans; // node-> size
    //     unordered_map<int,unordered_set<int>> edges; // edges, node->list(parent)
        
    //     // setup edges;
    //     int n=isConnected.size();
    //     for (int i=0;i<n;i++) {
    //         int node=i;
    //         edges[node]=i; // each node -> parent itself
    //         //这里假设有问题，并不能只是指向比自己小的数作为parent
    //         // 所以使用set， 全部插入
    //         for (int j=0;j<isConnected[i].size();j++) {                
    //             if (isConnected[i][j]==1 && j<node) {
    //                 edges[node].insert(j);
    //             }
    //         }
    //         //cout << "node " << node << "=> parent" << edges[node] << endl;
    //     }

    //     // union & find
    //     for (int i=0;i<n;i++) {
    //         int root=i;
    //         for (auto node:edges[i]) {
                
    //         }

    //         while (edges[root]!=root) {
    //             root=edges[root];
    //         }
    //         // now I got root
    //         cout << "add " << root << endl;
    //         ans.insert(root);
    //     }
    //     return ans.size();
    // }

    int findParent(int x,vector<int> &parents) {
        return parents[x]==x?x:findParent(parents[x], parents);
    }

    // 本题的算法应可推广GS的 forest题目
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parents(n,-1);
        // setup parents first;
        for (int i=0;i<n;i++) {
            parents[i]=i;
        }

        int groups = n; // 最大可能是goupds 个circle.
        for (int i=0;i<n;i++) {        
            for (int j=i+1;j<isConnected[i].size();j++) {                
                if (isConnected[i][j]==1) {
                    // 对于每个i,j ,findparent
                    auto p1 = findParent(i, parents);
                    auto p2 = findParent(j, parents);                    
                    if (p1!=p2) {  // 发现不同parent即合并
                        parents[p1] = p2; // union
                        // 绝了，相当于2个group合并成一个了
                        --groups; 
                    
                    }
                }
            }
        }
        return groups;
    }
};

int main() {
    Solution obj;
    // vector<vector<int>> m={{1,1,0},{1,1,0},{0,0,1}};
    // int num = obj.findCircleNum(m);
    // cout<< (num==2) << endl;
    //
    vector<vector<int>> m={{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    int num = obj.findCircleNum(m);
    cout<< (num==1) << endl;
}
