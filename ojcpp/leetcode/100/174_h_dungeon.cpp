#include <codech/codech_def.h>
using namespace std;

/*
Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
Output: 7
Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.
一个普通的DP题目
*/
namespace {
    class Solution {
    public:
        int calculateMinimumHP(vector<vector<int>>& dungeon) {
            int m = dungeon.size();
            int n = dungeon[0].size();
            vector<vector<int>>  dp(m,vector<int>(n,0));
            
            for (int i=m-1;i>=0;i--) {
                for (int j=n-1;j>=0;j--) {
                    if (i==m-1 && j==n-1) {
                        dp[i][j]=max(1-dungeon[i][j],1);
                    } else if (i==m-1) {
                        dp[i][j]=max(dp[i][j+1]-dungeon[i][j],1);                    
                    } else if (j==n-1) {
                        dp[i][j]=max(dp[i+1][j]-dungeon[i][j],1);
                    } else {
                        dp[i][j]=min(max(dp[i+1][j]-dungeon[i][j],1), max(dp[i][j+1]-dungeon[i][j],1));
                    }
                }
            }
            return dp[0][0];
        }
    };
}