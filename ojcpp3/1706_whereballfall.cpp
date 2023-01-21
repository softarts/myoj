#include <vector>
using namespace std;

/*
10:30PM
这题没甚么难度，就是太怪异了，像个撞球游戏，需要理解题意,撞到边框是不会弹回来的

*/
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        vector<int> dp;
        for (int j=0;j<n;j++) {
            dp.push_back(j);
        }
        
        for (int i=0;i<m;i++) {
            // for (int j=0;j<n;j++) {
            //     cout << dp[j] << " ";
            // }
            //cout << endl;
            for (int j=0;j<n;j++) {
                int col = dp[j];
                if (col<0 || col>=n) {
                    continue;
                }
                // detect block?
                if ((col>0 && grid[i][col]==-1 && grid[i][col-1]==1) || 
                    (col<n-1 && grid[i][col]==1 && grid[i][col+1]==-1)) {
                        //如果前后两个cell正好碰撞
                    dp[j]=-1;continue;// -1意味者球回不来了
                } else {
                    dp[j]+=grid[i][col];//否则就按照cell的数字移位
                }
                if (dp[j]>n-1) {
                    dp[j]=-1;continue;
                }
            }
            
        }
        return dp;
    }
    
};