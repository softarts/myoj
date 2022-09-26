#include <vector>
#include <iostream>

using namespace std;

// sort lambda
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
      if (nums.size()==1) return 0;
      sort(nums.begin(),nums.end(),[](const int & a, const int & b) -> bool {
          return a < b; }
      );
      int ans = 0;
      int minv = nums[0];
      for (int i=1;i<nums.size();i++) {
          minv=max(minv+1, nums[i]);
          ans+=(minv-nums[i]);
      }
      return ans;
    }
};

int main() {    
    vector<int> nums={3,2,1,2,1,7};
    cout << boolalpha << (Solution().minIncrementForUnique(nums)==6) << endl;
    return 0;
}