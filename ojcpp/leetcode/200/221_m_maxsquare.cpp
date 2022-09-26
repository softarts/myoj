//
// Created by rui.zhou on 3/28/2019.
//

/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
 */

#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m=matrix.size();
            if (m==0) return 0;
            int n=matrix[0].size();
            int ans=0;
            vector<vector<int>> dp(m,vector<int>(n,0));
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (matrix[i][j]=='1') {
                        dp[i][j]=1;
                        ans=max(ans,dp[i][j]);
                    }
                }
            }

            for (int i=1;i<m;i++) {
                for (int j=1;j<n;j++) {
                    if (matrix[i][j]=='1') {
                        dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                        ans=max(ans,dp[i][j]);
                    }
                }
            }
            return ans*ans;
        }
    };
}

DEFINE_CODE_TEST(221_maxsquare)
{
    Solution obj;
    {
        vector<vector<char>> m{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        VERIFY_CASE(obj.maximalSquare(m),4);
    }
}