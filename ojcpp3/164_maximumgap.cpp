#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


//Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
//这个题来考试其实并不好，因为有比较简单的解答

// 思路, O(N)的话，只能把整个长度分为多个slot
/*
看到排序，还要求线性时间空间复杂度，就要想到桶排序，bucket sort。
挺难的一道题,目的是找到排序之后的最大间隔。
1  3  5  9
min = 1 
max = 9
gap = 3
1  4  7  9

bucketsMin: 3 5 INF    区间中的最小值
bucketsMax: 3 5 -INF   区间中的最大值

time : O(n)
space : O(n)
11:54 -23
桶排序，只适合整数
*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {        
        if (nums.size()<=1) return 0;
        auto [low0,high0] = minmax_element(nums.begin(),nums.end());
        auto low = *low0;
        auto high = *high0;
        int n = nums.size();
        int gap = max((high-low)/(n-1),1); 
        int bs = (high-low)/gap+1;
        
        vector<int> bucketMin(bs, INT_MAX);
        vector<int> bucketMax(bs, INT_MIN);

        for (int num:nums) {
            int idx = (num-low)/gap;
            bucketMin[idx] = min(bucketMin[idx], num);
            bucketMax[idx] = max(bucketMax[idx], num);
        }
        int ans = INT_MIN;
        int prev=low;
        for (int i=0;i<bs;i++) {
            if (bucketMin[i]!=INT_MAX) {
                ans = max(ans, bucketMin[i] - prev);
                prev = bucketMin[i];
            }
            if (bucketMax[i]!=INT_MIN) {
                ans = max(ans, bucketMax[i] - prev);
                prev = bucketMax[i];
            }
        }
        ans = max(ans, high - prev);
        return ans;
    }
};