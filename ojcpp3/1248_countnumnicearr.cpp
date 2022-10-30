// 2022-10-03T20:42:44.000+08:00

/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
这个题目不是很清楚
以这个为例,只要包括odd number,并不用管其他数字
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

2,2,2,1,2,2,1 =>1
2,2,2,1,2,2,1,2 =>2

  2,2,1,2,2,1,2 ==> 如何表达这个？
  
2,2,2,1,2,2,1,2,2 =>3

2,2,2,1,2,2,1,2,2,2 =>4
  2,2,1,2,2,1,2,2,2 =>5
    2,1,2,2,1,2,2,2 =>6
      1,2,2,1,2,2,2 =>7
  2,2,1,2,2,1 =>2
    2,1,2,2,1 =>3
      1,2,2,1 =>4
      1,2,2,1,2, => 6
      1,2,2,1,2,2 => 7
      1,2,2,1,2,2,2 => 8

以上要考虑的组合太多了，考虑这个做法
求出最多K个奇数的count，再求出最多K-1个奇数的count，两者相减就是K个奇数的count:
K,K-1,K-2,...0
  K-1,K-2,...0
==> K  
*/

#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    int atMost(vector<int> &nums, int k) {
        int count = 0;
        int left = 0;
        for (int i=0;i<nums.size();i++) {
            k -= nums[i]%2;
            while (k<0) {// 表示超过计数了,调整k的个数
                k += nums[left++]%2;
            }
            //此时窗口的大小就代表了此时最多有k个奇数的子数组的个数
            //[1,1,2,1] => 1121,121,21,1 共四个
            //[1,1] => 11, 1 2种
            count+=i-left+1;
        }
        return count;
    }
};

// https://www.cnblogs.com/grandyang/p/15488415.html
// 再来看一种解法，这种思路的核心是统计偶数的个数，只需要一次遍历即可完成。
//还是要借用滑动窗口的方法，维护一个刚好有k个奇数的窗口，当首次将k个奇数放到窗口中时，
//当前窗口可能不是最短的，需要统计左起连续0的个数。比如数组数组是 [0, 0, 1, 0, 1, 0, 0]，
//k=2 时，则首次找到的窗口是 [0, 0, 1, 0, 1]，显然不是最短的，这里最短的窗口为 [1, 0, 1]，
//需要统计左起0的个数，有两个0，再加上最短的那个窗口，目前为止总共有三个子数组符合题意，加到结果 res 中。
//然后继续右移右边界，若还是遇到了偶数，则之前所有的情况再加上这个偶数，就又是一个新的子数
// 基本思路 [011]=>2个组合,0,1
// [2,2,2,1,2,1,2,2],2 ==>12
// class Solution {
// public:
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     int res = 0, left = 0, cnt = 0, n = nums.size();
    //     for (int i = 0; i < n; ++i) {
    //         if (nums[i] % 2 == 1) {
    //             --k;
    //             cnt = 0;
    //         }
    //         while (k == 0) {
    //             k += nums[left++] & 1;
    //             ++cnt;
    //         }
    //         res += cnt;
    //     }
    //     return res;
    // }
// };

int main() {
    Solution obj;
    {
        vector<int> arr = {2,2,2,1,2,2,1,2,2,2};
        auto actual = obj.numberOfSubarrays(arr,2);
        cout << boolalpha << actual<< ","<<(actual==16) << endl;
    }
    

}