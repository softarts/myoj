//
// Created by rui.zhou on 2/2/2019.
//

/*
 * https://leetcode.com/problems/number-of-islands/
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
 * You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

思路 都忘了是不是自己做的了


*/

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution0 {
    public:
        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty())
                return 0;
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<int>> dp(m,std::vector<int>(n));
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    dp[i][j]=0;
                }
            }
            int count=0;
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (dp[i][j]!=0)
                        continue;
                    if (bfs(i,j,grid,dp))
                        count++;
                }
            }
            return count;
        }

        bool bfs(int i, int j,vector<vector<char>>& grid,vector<vector<int>> &dp) {
            int m=grid.size();
            int n=grid[0].size();
            if (i>=m || j>=n || i < 0 || j < 0) {
                return false;
            }
            if (dp[i][j] == 1)
                return false;
            else if (dp[i][j] ==0 && grid[i][j]=='1') {
                dp[i][j] = 1;
                // right
                bfs(i,j+1,grid, dp);
                // down
                bfs(i+1,j,grid, dp);
                // up
                bfs(i-1,j,grid, dp);
                // left
                bfs(i,j-1,grid, dp);
                return true;
            } else {
                return false;
            }
        }
    };

    // 2021-10-30 attempt2
    class Solution {
    public:
        int ans = 0;
        int m,n;
        int numIslands(vector<vector<char>>& grid) {
            m = grid.size();
            n = grid[0].size();
            vector<vector<bool>> dp(m,vector<bool>(n, false));
            
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (grid[i][j]=='1' && !dp[i][j]) {
                        helper(i,j,grid,dp);
                        ans++;
                    }
                }
            }
            return ans;
        }
        
        
        void helper(int x, int y, vector<vector<char>>& grid, vector<vector<bool>> &dp) {
            if (x==m || y==n || y==-1||x==-1|| dp[x][y] || grid[x][y]=='0') {
                // visited or water
                return;
            }
            dp[x][y] = true;
            
            
            int dir[] = {0, 1, 0, -1, 0};
            for (int i=0;i<4;i++) {
                helper(x+dir[i],y+dir[i+1],grid,dp);
            }
            
        }
    };
}


DEFINE_CODE_TEST(200_numberofisland)
{
    Solution obj;
    {
        vector<vector<char>> grid{{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
        VERIFY_CASE(obj.numIslands(grid),1);
    }
    {
        vector<vector<char>> grid{{'1','1','0','1','0'},{'1','1','1','0','1'},{'0','0','1','1','0'},{'1','1','0','0','0'}};
        VERIFY_CASE(obj.numIslands(grid),4);
    }

}
