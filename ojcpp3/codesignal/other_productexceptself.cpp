#include <vector>
#include <numeric>
using namespace std;
/*
lc238
*/
int solution(vector<int> nums, int m) {
    vector<int> ans(nums.size(), 1);
    int product = 1;
    for (int i = 1; i < nums.size(); i++) {
        product = product * nums[i-1];
        ans[i] = product%m;
    }

    product = 1;
    for (int i = nums.size()-2; i >= 0; i--) {
        product = product * nums[i+1];
        ans[i] = ans[i]*product%m;
    }
    // sum of res
    int ret = accumulate(ans.begin(),ans.end(),0) % m;
    return ret;
}
