#include <string>
#include <stack>
#include <sstream>
using namespace std;

/*
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
使用一个栈来消除重复字符
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> sta;
        for (int i=0;i<s.length();i++) {
            if (sta.empty()) {
                sta.push(pair(s[i],1));
            } else {
                if (sta.top().first==s[i]) {
                    if (++sta.top().second==k) {
                        sta.pop();        
                    }
                } else {
                    sta.push(pair(s[i],1));    
                }
            }
            //cout<<sta.top().first<<" = "<< sta.top().second<<endl;
        }
        std::stringstream ss;
        while (!sta.empty()) {
            for (int i=0;i<sta.top().second;i++) {
                ss<<sta.top().first;
            }
            sta.pop();
        }
        string ans=ss.str();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};