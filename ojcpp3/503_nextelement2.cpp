
/*
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
[2, 1, 3, 4 ,3] =>  2 2 3 4 4 => [3,3,4,-1,4]
10:06
st,2,3,4 => 0,2,3,
ans => 3,3,4,
难题在于，如何解决这种: 4 2 3 5 => 5 3 5 x 
保留一个4 2 x x?

=> 栈，如果当前比栈顶大的数， 意味着是next greater element,把栈里的数popup直到遇到一个更大的
设置vector 默认为-1,精妙！
i%n来取模，因为是circle array
比栈的数大时就更新ans
*/
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for (int i=0;i<n*2;i++) {
            int cur=nums[i%n];
            while (!st.empty() && nums[st.top()]<cur) {
                ans[st.top()] = cur;
                st.pop();
            }
            if (i<n) st.push(i);
        }
        return ans;
    }
};