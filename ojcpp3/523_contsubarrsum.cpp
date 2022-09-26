#include <vector>

// yitu
// count, 输入 int 类型数组， 假设每个数都是正整数。
// nums[i] <= 1000, size(nums) <= 10000
// return int, 表示 多少个子串，序列和，是 7的倍数。
// 3, 6, 7, 1, 2, 7
// [7], [6, 7, 1], [7], return 3, 连续的

// 是否存在子串，和是k的整数倍
// 能否只用O(N)做到

// input: nums = [23,2,4,6,7], k = 6
// Output: true
// Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 记录每个remainder,如果得到同样的remainder，表明之间的sum必然是k的倍数
// 由于要连续2个元素，所以必须i-m[r]上一次的index>2
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> m{{0,-1}}; //remain->index
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];            
            int r = sum%k;
            if (m.count(r)) {
                if (i - m[r] > 1) return true; //表示在前一个数之后,但是i=0不行，因为>1不成立
            } else {
              m[r] = i;  //记下索引
            }
        }
        return false;
    }
};