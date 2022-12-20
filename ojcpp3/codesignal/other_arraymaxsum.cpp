#include <vector>
using namespace std;

/*
lc53
dp 的思路，当前dp最大值=前一个dp[-1]最大值+nums[i]，和nums[i]之间的最大值
*/
int solution(vector<int> inputArray) {
    int maxSum = INT_MIN;
    int curSum = INT_MIN;
    for (int i=0;i<inputArray.size();i++) {
        curSum = max(inputArray[i],curSum+inputArray[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}
