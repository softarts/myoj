#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int i=0,j=height.size()-1;
        while (i < j) {
            int h = min(height[i],height[j]);
            maxArea = max(maxArea, (j-i)*h);
            // 两者相等的时候，还是都要同时移动，不然只会越来越小
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;
        }
        return maxArea;
    }
};



int main() {
  vector<int> nums{1,8,6,2,5,4,8,3,7};
  int ret = Solution().maxArea(nums);
  cout << boolalpha << (ret == 49) << endl;
  return 0;
}