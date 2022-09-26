//2021-08-28
#include <codech/codech_def.h>
using namespace std;

//由于要求组合，这种题一般需要backtrace
//先求出所有的子字符串，然后dfs
namespace {
    class Solution {
    public:
        vector<string> wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(),wordDict.end());        
            vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
            
            for (int i=0;i<s.length();i++) {
                for (int j=0;j<=i;j++) {
                    dp[j][i]=dict.count(s.substr(j,i-j+1));
                    //cout<<j<<","<<i<<dp[j][i]<<endl;
                }
            }
            vector<string> comb;
            helper(0,s,comb,dp);
            return ans;
        }
                        
        vector<string> ans;
        void helper(int pos, string &s,vector<string> &comb,vector<vector<int>> &dp) {
            if (pos==s.length()) {
                string tmp=std::accumulate(begin(comb),end(comb),string(),[](const auto &a, const auto &b) {return a+(a.length()>0?" ":"")+b;});
                ans.push_back(tmp);
            }
            for (int i=pos;i<s.length();i++) {
                if (dp[pos][i]) {
                    comb.push_back(s.substr(pos,i-pos+1));
                    helper(i+1,s,comb,dp);
                    comb.pop_back();
                }
            }
        }
    };
}