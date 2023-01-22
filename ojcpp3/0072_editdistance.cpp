#include <string>
#include <vector>

using namespace std;

/*
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
计算变换的最小步数
极值一般考虑dp
考虑
dp[i][j] 为 w1i 到w2j需要的最小步数，那么i+1,和j+1的状态就依赖于前面, 从三种可能中选一个最小值
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        // init
        for (int i=0;i<=m;i++) {
            dp[i][0]=i;
        }
        for (int j=0;j<=n;j++) {
            dp[0][j]=j;
        }

        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                dp[i][j]=(word1[i-1]==word2[j-1])?dp[i-1][j-1]:min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
        return dp[m][n];
    }
};