#include <vector>
#include <iostream>
using namespace std;

/*
船只能横或者竖着排 1 row或者1col，之间隔开至少一个cell
求船的个数
能否只用one pass & O(1)内存， 并且不修改board

只向右或者下搜索，如果上/左为ship则忽略
这道题有点意思，真用不着dfs,直接数组遍历，还得followup 提醒
*/
class Solution {
public:
    bool isNewShip(vector<vector<char>>& board, int r, int c) {
        if (r-1>=0) {
            if (board[r-1][c]=='X') return false;
        }

        if (c-1>=0) {
            if (board[r][c-1]=='X') return false;
        }

        if (board[r][c]=='X') return true;
        return false;
    }

    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        int m=board.size();
        int n=board[0].size();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (isNewShip(board,i,j)) ans++;
            }
        }
        return ans;
    }
};