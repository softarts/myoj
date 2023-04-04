#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
这题的难点是O(1),如何做到？
看了下思路，精彩，记录每个点到左上角的和，到时直接计算。
pair<int,int> 没有对应的hash
使用dp的做法是重复计算了

*/
class NumMatrix0 {
public:
    unordered_map<int,int> m;
    // int row=0;
    // int col=0;
    int row=0,col=0;
    NumMatrix(vector<vector<int>>& matrix) {
        // int row=matrix.size();
        // int col=matrix[0].size();
        row=matrix.size();
        col=matrix[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,0));
        
       for (int i=1;i<=row;i++) {
            for (int j=1;j<=col;j++) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }

        for (int i=1;i<=row;i++) {
            for (int j=1;j<=col;j++) {
                //cout << dp[i][j] <<" ";
                m[(i-1)*col+(j-1)]=dp[i][j];
            }
            //cout<<endl;            

        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1=(row1-1>=0 && col1-1>=0)?m[(row1-1)*col+(col1-1)]:0;
        int sum2=(row1-1>=0)?m[(row1-1)*col+col2]:0;
        int sum3=(col1-1>=0)?m[row2*col+(col1-1)]:0;
        int sum4=m[row2*col+col2];
        return (sum4-sum2-sum3+sum1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// 优化版本
class NumMatrix {
public:    
    int row=0,col=0;
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {        
        row=matrix.size();
        col=matrix[0].size();
        dp.resize(row+1,vector<int>(col+1,0));        
        
       for (int i=1;i<=row;i++) {
            for (int j=1;j<=col;j++) {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1=dp[row1-1+1][col1-1+1];        
        int sum2=dp[row1-1+1][col2+1];
        int sum3=dp[row2+1][col1-1+1];        
        int sum4=dp[row2+1][col2+1];
        return (sum4-sum2-sum3+sum1);
    }
};