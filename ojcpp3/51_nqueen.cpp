#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> comb;
        helper(n,0,comb);
        return ans;
    }
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
            vector<string> tmp;
            for (int j=0;j<comb.size();j++) {
                string s;
                for (int i=1;i<=n;i++) {
                    s+=(i==comb[j]?"Q":".");
                }
                tmp.push_back(s);
            }
            ans.push_back(tmp);
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
};

