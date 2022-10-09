#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {        
        sort(words.begin(),words.end());
        unordered_map<string,int> m;
        for (auto & it:words) {
            cout<<it<<endl;
            m.insert(pair(it,1));
        }
        
        int ans=1;
        for (auto &s:words) {
            int n = s.length();           
            for (int i=0;i<n;i++) {
                // TODO add handle char at begin or end;
                // loop the each char of the string, take out one char and construct a new str
                // e.g. bda=> da,ba,bd
                auto newStr = s.substr(0,i) + s.substr(i+1);

                // search if da, ba, bd is already in map            
                if (m.count(newStr)) {
                    // e.g ba is in the map, and ba=2                
                    // ba(1) =>b(1)=>found `b` in map, ba=>2, 
                    // ba(1) =>a(1)=>found `a` in map, ba=>2                    
                    m[s] = max(m[s], 1+m[newStr]);
                }
            }
            ans=max(ans,m[s]);
        }
        return ans;
    }
};
