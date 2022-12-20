#include <vector>
using namespace std;
/*
lc51 hard
给出 nxn 棋盘，如何排放queen
12:47 - 1:16 (30min) 正好在时间内
lc51 只有java code.当时可能还不懂怎么做
*/
vector<vector<int>> ans;
bool valid(vector<int> &comb, int col) {
    if (find(comb.begin(),comb.end(),col)!=comb.end()) return false;
    int sz = comb.size();
    
    int tmp0=col;
    int tmp1=col;
    for (int i=sz-1;i>=0;i--) {
        if (comb[i]==--tmp0 || comb[i]==++tmp1) {
            return false;
        }
    }
    return true;
}

void helper(int n, int x, vector<int> &comb) {
    if (x==n) {
        ans.push_back(comb);
        return;
    }
    for (int col=1;col<=n;col++) {
        if (valid(comb,col)) {
            comb.push_back(col);
            helper(n, x+1, comb);
            comb.pop_back();
        }
    }
}

vector<vector<int>> solution(int n) {
    vector<int> comb;
    helper(n,0,comb);
    return ans;
}
