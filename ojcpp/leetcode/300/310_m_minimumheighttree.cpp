#include <codech/codech_def.h>
using namespace std;

/*
2021-08-28
难点是如何判断到底，因为是个无方向的图
这个用dfs是难解的，很难判断何时结束（叶结点）

方法，
1.找出所有只有一个edge的点，加入queue
2.在一个while循环里，处理所有节点直到最后只剩下2个
3.对queue中所有元素,一次性的处理掉，(从其peer的edge移除，如果peer只剩下一个edge，则加入queue)，
一次性处理的原因是，要保证全部处理所有单边连接的node，否则可能造成while条件不满足

*/

namespace {
    class Solution {
    public:    
        vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
            if (n==1) return vector<int>{0};
            unordered_map<int,unordered_set<int>> m;
            for (auto &v:edges) {
                m[v[0]].insert(v[1]);
                m[v[1]].insert(v[0]);
            }

            deque<int> deq;

            for (auto &vec:m) {
                if (vec.second.size()==1) {
                    deq.push_back(vec.first);
                    cout<<"add "<<vec.first<<endl;
                }
            }


            while (n>2) {
                int dl= deq.size();
                n-=dl;
                for (int i=0;i<dl;i++) {
                    int u=deq.front();
                    deq.pop_front();
                    for (auto &v:m[u]) {
                        m[v].erase(u);
                        if (m[v].size()==1) {
                            deq.push_back(v);
                        }
                    }
                }
            }

            vector<int> ans(deq.begin(),deq.end());
            return ans;
        }
    };
}