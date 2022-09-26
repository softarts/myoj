#include <codech/codech_def.h>

using namespace std;

//84, -37, 32, 40, 95
// 因为有负数的可能，所以不能通过缩减滑动窗口
//使用presum
namespace {
    class Solution {
    public:
        int shortestSubarray(vector<int>& nums, int k) {
            vector<int> presum(nums.size()+1,0);
            for (int i=1;i<=nums.size();i++) {
                presum[i]=nums[i-1]+presum[i-1];
            }

            //sliding window
            deque<int> deq{0};
            int minLen = INT_MAX;
            for (int i=1;i<presum.size();i++) {
                while (!deq.empty() && presum[i]-presum[deq.front()]>=k) {
                    minLen = min(minLen,i-deq.front());
                    deq.pop_front();
                }

                while (!deq.empty() && presum[deq.back()]>presum[i]) {
                    deq.pop_back();
                }
                deq.push_back(i);
            }
            if (minLen==INT_MAX) return -1; else return minLen;
        }
    };
}