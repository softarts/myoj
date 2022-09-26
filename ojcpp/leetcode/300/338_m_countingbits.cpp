//
// Created by rui zhou on 2019-09-02.
//

/* https://leetcode.com/problems/counting-bits/
 * Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

 规律是，从1开始，遇到偶数时，其1的个数和该偶数除以2得到的数字的1的个数相同，
 遇到奇数时，其1的个数等于该奇数除以2得到的数字的1的个数再加1

 下面这种方法就更加巧妙了，巧妙的利用了 i&(i - 1)， 这个本来是用来判断一个数是否是2的指数的快捷方法，比如8，二进制位 1000, 那么 8&(8-1) 为0，只要为0就是2的指数, 那么我们现在来看一下0到 15 的数字和其对应的 i&(i - 1) 值：
 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        vector<int> countBits(int num) {
            vector<int> table(num+1);
            table[0] = 0;
            for (int i=0;i<=num;i++) {
                table[i] = table[i/2] + i%2;
            }
            return table;
        }
    };
}


DEFINE_CODE_TEST(338_countingbits)
{
    Solution obj;
    {
        obj.countBits(5);

    }
}