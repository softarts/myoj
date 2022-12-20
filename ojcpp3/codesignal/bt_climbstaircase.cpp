#include <vector>
using namespace std;

/*
因为需要记下步骤，所以用backtracking

*/
void helper(vector<vector<int>> &ans, int target, int k, vector<int> &comb) {
    if (target==0) {
        ans.push_back(comb);
        return;
    }

    for (int i=1;i<=k && i<=target;i++) {
        comb.push_back(i);
        helper(ans,target-i,k,comb);
        comb.pop_back();
    }
}

vector<vector<int>> solution(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb;
    helper(ans, n, k, comb);
    return ans;
}




