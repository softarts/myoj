#include <vector>

using namespace std;

/*
如何处理每次只能移动n-1个元素？

把其中最小的n-1个元素都++ 相当于 把最大的元素–1 的操作 这个还是有点难理解
例如某个状态： 6,6,6,7, 那么需要7移动一次
5，6，7，8=>5,6,7,7 (1)=> 5,6,6,6 (1+2) => 5,5,5,5(1+2+3=6)

暴力过程:
排序, 然后只增加前n-1个元素，再排序， 再增加前n-1个元素, 直到第一个和最后一个相等，TLE

To make elements equal, it means we need to make the difference between min element and max element in array equal to 0.
In each move, we can increase all n-1 elements by one. We should never choose to increase our max element, so we choose to increase other elements except our current max element, it means we decrease the difference between the max element and the min element by one.
So in each move, we need to decrease the current max element by one to util every elements become min element.
The problem become: count difference between other elements with our min element in the array.

*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minv = nums[0];
        for (int x : nums) {
            minv = min(minv, x);
        }
         
        int ans = 0;
        for (int x : nums) 
            ans += x - minv;
        return ans;

    }
};