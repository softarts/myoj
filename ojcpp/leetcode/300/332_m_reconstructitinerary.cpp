#include <codech/codech_def.h>
#include <set>
using namespace std;

/*
这题的特点是DFS， 还要考虑要完成所有行程
1. 两点之间会有多个连接，想着用backtrace比较复杂，如何判断退出条件?
2.通过判断某个点是否还有到别的城市的egde来决定他的行程是否已结束--关键,
3. 结束的话输出在front,因为是递归调用，最后的先输出
*/
namespace {
    class Solution {
    public:
        //unordered_map<string, priority_queue<string, vector<string>, greater<string>>> it_map;
        unordered_map<string, multiset<string>> it_map;
        list<string> ans;
        
        void DFS(string origin) {
            if(!it_map[origin].empty()) {
                while(!it_map[origin].empty()) {
                    //string next = it_map[origin].top();
                    auto nextIt = it_map[origin].begin();
                    string next = *nextIt;
                    it_map[origin].erase(nextIt);
                    cout<<"try "<<next<<endl;
                    DFS(next);
                }
            }
            cout<<origin<<endl;
            ans.push_front(origin);
        }
        
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            int n = tickets.size();
            for(auto ticket: tickets) {
                if(it_map.find(ticket[0]) == it_map.end()) {
                    //priority_queue<string, vector<string>, greater<string>> pq;
                    multiset<string> pq;
                    it_map[ticket[0]] = pq;
                }
                it_map[ticket[0]].insert(ticket[1]);
            }
            
            DFS("JFK");
            
            //vector<string> tmp;
            //transform(ans.begin(), ans.end(),[](string &v){return stoi(v);},inserter(tmp));
            return vector<string>(ans.begin(), ans.end());
            //return tmp;
        }
    };
}