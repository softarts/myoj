#include <vector>
#include <iostream>

using namespace std;
//ubiquant 笔试题
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int f1=0;
        int f2=nums[0];
        int ans=f2;
        for (int i=1;i<nums.size();i++) {
            ans=max(f2,f1+nums[i]);
            f1=f2;
            f2=ans;
        }
        return ans;
    }
};

int main() {
  vector<int> arr = {2,4,6,2,5};
  auto sol = Solution();
  cout << boolalpha << (sol.rob(arr)==13) << endl;
  vector<int> arr1 = {5,1,1,5};
  cout << boolalpha << (sol.rob(arr1)==10) << endl;
  vector<int> arr2 = {5,9,6,6,100};
  cout << boolalpha << (sol.rob(arr2)==111)<< endl;    
  return 0;
}