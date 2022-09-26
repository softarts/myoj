#include <vector>
#include <iostream>

using namespace  std;

/*
two elements appear only once and all the other elements appear exactly twice.
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
要求O(N)和空间O(1)，不能用hashmap
这个题考虑xor bit有些过了，意义也不大
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int totalXor=0, n = nums.size();
        // 所有元素互相xor, 相同的会得到0: 2^2=0; 0^X=X
        // 所以totalXor= X^Y
        for (auto i=0;i<n;i++) {
            totalXor^=nums[i];
        }
        
        // 由于A跟B是不一样的数，所以A∧B≠0A∧B≠0，因此A∧BA∧B的二进制表示中至少存在一个bit是1。根据异或的定义，这个bit是1，表明了在该位置上，AA和BB对应的bit一个是1，一个是0。
        // 我们可以使用这个bit作为一个标志位，对原来的数组的元素进行划分。假设是第i个bit为1，那么我们设置一个变量bitFlag，bitFlag仅在第i个bit为1，其它bit都为0，用bitFlag与数组中的元素相与，相与结果为0的归为第1组，相与结果不为0的归为第2组，这样AA和BB肯定分开在这两组中。假如A在该bit上是0，B是1，那么A就会在第1组，B在第2组，反之亦然。 同时，相同的数会分在同一组中，这样实现了之前我们的想法，把复杂的问题转为以前解决过的简单问题。
        // 找出X 和 Y差异的那一位， 
        // x ^ (x-1) => 消掉最末那个1
        // x ^ ~(x-1) => 找出为1的那一个bit
        int diffBit=totalXor & ~(totalXor-1);
        int num1=0,num2=0;
        //分成两组
        for (auto i=0;i<n;i++) {
            if (nums[i]&diffBit) {
                num1^=nums[i];
            } else {
                num2^=nums[i];
            }
        }
        return vector<int>{num1,num2};
    }
};
