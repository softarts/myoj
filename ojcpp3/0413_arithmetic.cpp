#include <vector>
using namespace std;

// 1 2 3 --> 1
// 1 2 3 4 -> 3 (123,234,1234) +2
// 1 2 3 4 5 -> 6(123,234,345,1234,2345,12345) +3
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size()<3) return 0;
        int ans=0;
        int addend=0;
        for (int i=1;i<nums.size()-1;i++) {
            if (nums[i]-nums[i-1] == nums[i+1]-nums[i]) {
                ans+= ++addend;
            } else {
                addend=0;
            }
        }
        return ans;
    }
};
