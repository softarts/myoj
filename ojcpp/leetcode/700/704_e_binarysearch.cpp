#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            if (nums.empty()) return -1;
            int start=0;
            int end=nums.size()-1;
            while (start<end) {
                int mid = (start+end)/2;
                if (nums[mid] == target) {
                    return mid;
                } else if (nums[mid] < target) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            }
            
            if (nums[start]==target) return start;//这一步可能多余
            return -1;
        }
    };
}