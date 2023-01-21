#include <vector>
using namespace std;

/*
8:46 PM
暴力法， 30分钟内应该可以
意思不大
*/
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int sum=0;

        auto calc=[&](int row,int col) {
            int sum=0;
            for (int i=row;i<row+3;i++) {
                for (int j=col;j<col+3;j++) {
                    // cout << i << "," << j << "=" << !(i==row+1 && j==col) <<endl;
                    // cout << i << "," << j << "=" << !(i==row+1 && j==col+2) <<endl;
                    if (!(i==row+1 && j==col) && !(i==row+1 && j==col+2)) {
                        // cout<<grid[i][j] << " "<<endl;; 
                        sum+=grid[i][j];
                    }
                }
            }
            return sum;
        };

        
        int maxv=INT_MIN;
        for (int i=0;i<=m-3;i++) {
            for (int j=0;j<=n-3;j++) {
                maxv=max(maxv,calc(i,j));
            }
        }
        return maxv;  
    }
};