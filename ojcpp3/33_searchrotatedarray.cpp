#include <vector>
using namespace std;

// [4,5,6,7,8,9,0,1,2]
// 这个题的情况比较复杂，需要都考虑到

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while (low<=high) {// 因为需要比较到最后low/high，所以使用<=
            int mid=(low+high)/2;
            if (nums[mid]==target) {
                return mid;
            } else if (nums[mid] > nums[high]) {
                // 解法特点就是这里没有比较target和mid，而是先区分情况
                // 再比较target决定下一步的搜索范围
                if (target<nums[mid] && target >= nums[low]) {
                    high=mid-1; // 只有这种情况需要search in left
                } else {
                    low = mid+1; // search in right
                }
            } else if (nums[mid] < nums[low]) {
                //left part rotated
                if (target>nums[mid] && target <=nums[high]) { //right is sort
                    low = mid + 1; //决定下一步在那里搜索
                } else {
                    high = mid-1;
                }
            } else {
                // 剩下的情况就是sorted
                if (target>nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};