#include <codech/codech_def.h>
using namespace std;

/*
如何区分有环和无环的情况
这个题借鉴了332的做法，但是效率稍有不足，把所有链接在一起的node删掉

dfs函数用于递归遍历所有连接点，但是没考虑visited

*/

namespace {
    class Solution {
    public:
        unordered_map<int,unordered_set<int>> m;
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n =  isConnected.size();     
            for (int i=0;i<n;i++) {
                auto &vec = isConnected[i];
                for (int j=0;j<vec.size();j++) {
                    if (vec[j]==1) {
                        m[i].insert(j);// 双向，无法避免
                    }
                }
            }
            int ans=0;
            int prev=m.size();
            //cout<<m.size()<<endl;
            for (int i=0;i<n;i++) {
                vector<bool> visited(n,false);
                if (m.count(i)) {
                    dfs(i, visited);
                }
                //cout<<prev<<","<<m.size()<<endl;
                if (m.size()!=prev) {
                    ans++;
                }
                prev=m.size();
            }
            ans+=m.size();
            return ans;
        }


        void dfs(int origin, vector<bool> &visited) {
            if (visited[origin]) return;
            visited[origin] = true;
            //cout<<"dfs "<<origin<<" sz="<<m[origin].size()<<endl;
            while (!m[origin].empty()) {
                auto nextIt = m[origin].begin();
                int next = *nextIt;
                m[origin].erase(nextIt);
                if (origin!=next) {
                    dfs(next,visited);
                }
            }
            m.erase(origin);
            //cout<<"delete "<<origin<<endl;
        }
    };
}