#include <vector>
using namespace std;

/*
Input: nums = [1,3,5,2], cost = [2,3,1,14]
Output: 8
Explanation: We can make all the elements equal to 2 in the following way:
- Increase the 0th element one time. The cost is 2.
- Decrease the 1st element one time. The cost is 3.
- Decrease the 2nd element three times. The cost is 1 + 1 + 1 = 3.
The total cost is 2 + 3 + 3 = 8.
It can be shown that we cannot make the array equal with a smaller cost.
每一个元素都有cost,如何找到平衡点？
不太像dp，没有子状态,
二分查找比较接近？high and low?
*/
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
    }

};