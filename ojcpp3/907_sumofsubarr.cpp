#include <vector>
using namespace std;


//Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

/*
使用了monotonnic
针对每个子数组，取其最小者，然后求sum
以 A[i] 为最小值可以形成的子数组的数量 = i 到左边界的距离 * i 到右边界的距离。
例如这里的[3,1,2,4] ，1所能覆盖的, 2*3*(1)=6
*/

#include <stack>
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        deque<int> deq;
        int n=arr.size();
        long ans=0;
        for (int i=0;i<=n;i++) {
            int cur = (i==n?INT_MIN:arr[i]);
            while (!deq.empty() && cur < arr[deq.back()]) {
                int j = deq.back();
                deq.pop_back();
                int left = deq.empty()?-1:deq.back();
                ans+= arr[j]*(long(j-left))*(long(i-j));
                //ans+= arr[j]*(j-left)*(i-j)%MOD;
            }
            deq.push_back(i);
        }
        return (ans%(long)MOD);
    }
};