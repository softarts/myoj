#include <vector>
using namespace std;

/*
2:31PM
找出是否有1 3 2 pattern
Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


99, 101, 1, 3, 2 => 1,3,2
99, 101, 1, 2, 3, 100  => 99,101,100;
99, 101, 1, 2, 3, 100, 2 => 99,101,100;  1,3,2
99, 100, 1, 2, 3, 100, 2 =>  1,3,2
难点是如何区分以上情况?即使左右均形成单调栈，但还要保证右栈的最小值要大于左栈的最小值1，小于左栈的最大值===>20分钟没做出来失败

- 关键， 找出最高峰的 3 和次高峰的2, 逆向遍历
- st 里永远保存1 ~ 3 之间的序列， 并且这些数都是大于third，这样被st弹出的数据就成为third
- 99, 94,95,100,90 ==> 重新调整为 99, 95(成为新的third)， 关键取得一个尽可能大的third，这样可以覆盖更多的case
很精彩的stack题
*/

#include <stack>

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st;
        for (int i=nums.size()-1;i>=0;i--) {
            if (nums[i]<third) {
                return true;
            }
            while (!st.empty() && nums[i]>st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};