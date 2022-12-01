#include <vector>
using namespace std;

/*
考虑 a,b,c 一定是中位数b, 假如是b+1=> b-a+1,1, c-b-1 => c-a+1
=> b-a, c-b =>c-a 
中位数移动最少
*/
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int mid = nums.size()/2;
        int pivot = nums[mid];
        for (auto el:nums) {
            ans+=abs(el-pivot);
        }
        return ans;
    }
};