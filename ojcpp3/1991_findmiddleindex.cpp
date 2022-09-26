#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int left = 0, right = sum;
        for (int i=0;i<nums.size();i++) {
            right-=nums[i];
            if (left == right) {
                return i;
            } else {
                left+=nums[i];
            }
        }
        return -1; 
    }
};

int main() {
  vector<int> a = {2,3,-1,8,4} ;
  int ret = Solution().findMiddleIndex(a);
  cout << (ret==3) << endl;
  return 0;
}