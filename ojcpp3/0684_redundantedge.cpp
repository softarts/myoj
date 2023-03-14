#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
将graph变成tree,类似lc261

*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,int> m;
        for (auto &iter:edges) {
            int r0=findRoot(iter[0],m);
            int r1=findRoot(iter[1],m);
            if (r0!=r1) {
                m[r0]=r1;
            } else {
                return vector<int>{iter[0],iter[1]};
            }
        }
        return vector<int>();
    }
    
    int findRoot(int node, unordered_map<int,int> &m) {
        while (m.count(node)) node=m[node];
        return node;
    }
};