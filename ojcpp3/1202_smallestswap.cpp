#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;


// TLE 
/*
能否有更好的做法?
分成几个group， 对每一个group 进行排序
For str = "abdc" and pairs = [[1, 4], [3, 4]], the output should be
solution(str, pairs) = "dbca".

1-4
3-4
=>

1-4
3-4
3-2
=>1-4,3-4,4-2

1-4
4-3
3-3

groups[3]->1,4,3

[[0,3],[1,2],[0,2]]

0-3
3-3


1-2
0-2
2-2

=> 3-2

*/
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> nodes;
        int n = s.length();
        // init nodes
        for (int i=0;i<n;i++) {
            nodes.push_back(i);
        }

        auto findRoot = [&](int i){
            int j=i;
            while (nodes[j]!=j) {
                j=nodes[j];
            }
            return j;
        };

        // set nodes parent
        for (auto &v:pairs) {
            auto root0 = findRoot(v[0]);
            auto root1 = findRoot(v[1]);

            if (root0!=root1) {
                nodes[root0] = root1;    
            } 
        }

        // union and find groups
        unordered_map<int, vector<int>> m;
        for (int i=0;i<n;i++) {
            auto root=findRoot(i);
            m[root].push_back(i);
            // nodes[i] = root;
        }

        for (auto &it: m) {
            vector<int> &v = it.second;
            sort(v.begin(),v.end());
            string tmp;
            for (auto &idx:v) {
                tmp+=s[idx];
            }
            sort(tmp.begin(),tmp.end());
            for (int i=0;i<v.size();i++) {
                s[v[i]] = tmp[i];
            }
        }
        return s;
    }

    // TLE
    string smallestStringWithSwaps0(string s, vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> m;
        for (auto &v:pairs) {
            m[v[0]-1].push_back(v[1]-1);
            m[v[1]-1].push_back(v[0]-1);
        }
        
        // 通用的做法
        auto getList=[&](int i) {
            unordered_set<int> s{i};
            deque<int> q{i};
            
            while (!q.empty()) {
                int id = q.front();
                q.pop_front();
                for (auto nid: m[id]) {
                    if (!s.count(nid)) {
                        s.insert(nid);
                        q.push_back(nid);
                    }    
                }
            }
            return vector<int>(s.begin(),s.end());
        };
    
    // auto debug=[](vector<int> &v) {
    //     for (auto &el:v) {
    //         cout << el << " ";
    //     }
    //     cout << endl;
    // };
    
        for (int i=0;i<s.length();i++) {
            vector<int> lst = getList(i);
            // sort(lst.begin(),lst.end());
            // debug(lst);
            
            for (auto el:lst) {
                if (s[i]<s[el] && (i<el)) {
                    // cout << "before swap " << str << endl;
                    // cout << "swap " << str[i] << "," << str[el] << endl;
                    swap(s[i],s[el]);
                    // cout << "after swap " << str << endl;
                }
            }
        }
        return s;
    }
};
