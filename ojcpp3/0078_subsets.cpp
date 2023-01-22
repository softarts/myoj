#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans = {{}}; 
    
    for (int i = 0; i < nums.size(); i++) {            
      int n=ans.size();
      for (int j = 0; j < n; j++) {
        ans.push_back(ans[j]);
        ans.back().push_back(nums[i]);
      }
    }
    return ans;
  }
};


int main() {
  return 0;
}