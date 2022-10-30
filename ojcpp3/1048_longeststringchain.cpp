#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 以前做过，居然想不起来
// boa 题目，这题是非常典型的array，首先排序array，
// 建立一个map[string]=1
// 然后把每个新的字符串拆出来，看看在不在map里面,在的话递归更新count，可以取前一个的count，累计到本count上
// 关键，如何判断是前后是一个chain, LCS =>x, backtrack => x
// 可以逐个字符比较，计数=较短的str
class Solution {
public:
    int longestStrChain(vector<string>& words) {        
        sort(words.begin(),words.end(),[](const string &a,const string& b){
            return a.length()<b.length();
        });
        unordered_map<string,int> m;
        for (auto & it:words) {
            // cout<<it<<endl;
            m.insert(pair(it,1));
        }
        
        int ans=1;
        for (auto &s:words) {
            int n = s.length();           
            for (int i=0;i<n;i++) {                
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
