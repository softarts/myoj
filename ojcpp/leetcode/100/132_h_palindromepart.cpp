#include <codech/codech_def.h>
using namespace std;

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
2021-08-26
先分解成多个palindrome，再计算最小的次数
*/
namespace {
    class Solution {
    public:
        int minNumber=INT_MAX;
        int minCut0(string s) {
            vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));

            for (int i=0;i<s.length();i++) {
                dp[i][i]=1;// it is palindrome!
                for (int j=0;j<i;j++) {
                    dp[j][i]=(i-j==1 && s[i]==s[j]) || (dp[j+1][i-1]==1 && s[j]==s[i]);
                }
            }
            int count=0;
            dfs(0,s,dp,count);
            return minNumber;
        }
        //TLE
        void dfs(int start,string &s,vector<vector<int>> &dp,int &count) {
            if (start==s.length()) {
                minNumber=min(minNumber,count-1);
                return;
            }

            for (int i=start;i<s.length();i++) {
                if (dp[start][i]) {
                    count++;
                    dfs(i+1,s,dp,count);
                    count--;
                }
            }
            //return ans;
        }

        //这个竟然可以
        int minCut(string s) {
            vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
            vector<long> cut(s.length()+1,INT_MAX);
            cut[0]=-1;//这是为了保证第一个回文实际不需要切割
            //使用cut[i]来记下0-i位置的最小cut次数，状态方程是，如果dp[i][j]
            // 当求出palindrom的组合之后，
            for (int i=0;i<s.length();i++) {
                dp[i][i]=1;// it is palindrome!
                for (int j=0;j<=i;j++) {
                    if (s[i]==s[j] && (i-j<=1 || dp[j+1][i-1]==1)) {//<=1是为了i==j的时候也能进来处理cut[x]
                        dp[j][i]=1;
                        cut[i+1] = min(cut[i+1],1+cut[j]);//这里怎么确认j-1位置可分割？
                        //cout<<i<<","<<j<<" cut"<<"="<<cut[i+1]<<endl;
                    }

                }
            }

            return cut[s.length()];
        }


    };
}