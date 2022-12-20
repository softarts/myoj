#include <vector>
using namespace std;

/*
从array中找出subset， 之和=num，每个数字只能用一次
需要剪枝避免
1,2,2,3  target=6 => 两次1,2,3的情况，
*/
vector<vector<int>> ans;
void helper(int start, vector<int> &arr, int target, vector<int> &memo) {
    if (target==0) {
        ans.push_back(memo);
        return;
    }
    for (int i=start;i<arr.size()&&arr[i]<=target;i++) {
        // 假如在同一个循环里，并且等于前者，那么跳过
        if (i>start && arr[i]==arr[i-1]) continue;
        memo.emplace_back(arr[i]);
        helper(i+1, arr, target-arr[i],memo);
        memo.pop_back();
        
    }
}
vector<vector<int>> solution(vector<int> arr, int num) {
    vector<int> memo;
    helper(0, arr, num, memo);
    return ans;
}
