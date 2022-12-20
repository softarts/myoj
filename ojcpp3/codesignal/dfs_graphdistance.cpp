#include <vector>
using namespace std;

/*
给出一个图，找出s到各个点的最小距离
g = [[-1, 3, 2],
     [2, -1, 0],
     [-1, 0, -1]]
思路 dfs 每个节点，如果weight小于已知距离则不再继续(作为退出条件)
优化：{
    
}
*/
vector<vector<int>> dis;
void helper(vector<vector<int>> &g, int node, int sum, int s) {
    // cout << "dfs "<< s << "->" << node<<endl;
    for (int next=0;next<g[node].size();next++) {
        if (node == next ) {
            dis[node][next] = 0;
            continue;
        }
        if (g[node][next]==-1) continue;
        auto newDis = g[node][next] + sum;
        if (newDis<dis[s][next]) {
            dis[s][next] = newDis;
            helper(g,next,newDis,s);
        }
    }
}
vector<int> solution(vector<vector<int>> g, int s) {
    dis.resize(g.size(),vector<int>(g.size(),INT_MAX));
    helper(g,s,0,s);

    return dis[s];
}