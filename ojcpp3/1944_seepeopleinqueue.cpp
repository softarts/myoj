/*
nput: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.
There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

和skyline那几道题类似，这道题的解法要构造一个monotonic stack 单调栈，同时注意
每次pop出栈顶元素的时候，需要计数，因为
7=>6,8,11, 只能看到6,8， 如果是10的话，能看到6,8,11
*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        stack<int> st({heights[n-1]});
        vector<int> ans{0};
        for (int i=n-2;i>=0;i--) {
            int count=0;
            while (!st.empty() && st.top()<heights[i]) {
                st.pop();count++;
            }
            if (st.empty()) {
                ans.push_back(count);
            } else {
                ans.push_back(count+1);
            }
            st.push(heights[i]);
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};