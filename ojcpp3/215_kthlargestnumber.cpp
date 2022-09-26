#include <vector>
using namespace std;

//o(N) 的做法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size() - k;//转换成要找的n
        int low = 0;
        int high = nums.size() - 1;
        int cut = partition(nums, low, high);
        while (cut != n) {//不是n
            if (cut < n) {
                low = cut + 1;
            }
            else  {
                high = cut - 1;
            } 
            cut = partition(nums, low, high);
        }
        return nums[n];
    }

    // partition的一种是实现
    int partition(vector<int>&arr, int low,int high) {
        int pivot = arr[low];
        while (low < high) {
            while (low<high && arr[high]>=pivot) high--;
            arr[low] = arr[high];
            while (low<high && arr[low]<=pivot) low++;
            arr[high]=arr[low];
        }
        arr[low]=pivot;
        return low;
    }

    //只能死记
    //是所有小于pivot的数都在左侧
    int partition2(vector<int> &nums, int low, int high) {
        int randIdx = rand() % (high - low + 1) + low;
        swap(nums[randIdx], nums[high]);            
        int pivot = nums[high];
        int w = low;  // 写入的位置
        for (int i=low;i<=high;i++) {
            if (nums[i]<pivot) {
                // 写入位置保证小于pivot
                // 如果大于pivot, 则跳过，不动写入位置，等下一次时再交换
                swap(nums[w++], nums[i]);  //
            }
        }
        swap(nums[w], nums[high]); // 最后交换写入位置和pivot,该写入位置必定大于pivot
        return w;  // 返回写入位置
    }
};
