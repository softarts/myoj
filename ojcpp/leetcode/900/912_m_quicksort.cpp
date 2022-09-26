#include <codech/codech_def.h>
using namespace std;


namespace {
    class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            qsort(nums,0,nums.size()-1);
            return nums;
        }
        
        // 程序入口
        // O(LogN)
        void qsort(vector<int> &nums, int low, int high) {
            if (low < high) {
                int mid = partition(nums, low, high);
                //cout << mid <<endl;
                qsort(nums,low,mid-1);
                qsort(nums,mid+1,high);
            }
        }
        
        // 分区,参数为数组，起点和结束
        // 随机取任意一个为pivot, 复杂度O(N)
        // 如果固定取最后一个，对于已排序的数组，可能会使分堆不均匀，上层恶化为O(N)
        int partition(vector<int> &nums, int low, int high) {
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
}