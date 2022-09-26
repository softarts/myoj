//
// Created by rui.zhou on 3/10/2019.
//

/*
 * Normally, the factorial of a positive integer n is the product of all positive integers less than or equal to n.  For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.

We instead make a clumsy factorial: using the integers in decreasing order, we swap out the multiply operations for a fixed rotation of operations: multiply (*), divide (/), add (+) and subtract (-) in this order.

For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.  However, these operations are still applied using the usual order of operations of arithmetic: we do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

Additionally, the division that we use is floor division such that 10 * 9 / 8 equals 11.  This guarantees the result is an integer.

Implement the clumsy function as defined above: given an integer N, it returns the clumsy factorial of N.



Example 1:

Input: 4
Output: 7
Explanation: 7 = 4 * 3 / 2 + 1
Example 2:

Input: 10
Output: 12
Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1


Note:

1 <= N <= 10000
-2^31 <= answer <= 2^31 - 1  (The answer is guaranteed to fit within a 32-bit integer.)
 */
#include <codech/codech_def.h>
using namespace std;

namespace c127clumsy {
    class Solution {
    public:
        int clumsy(int N) {
            int loop=N/4;
            int mod = N%4;
            int way=1;
            int sum=0;
            for (int i=N;i>mod;i-=4) {
                sum+=way * i * (i-1)/(i-2)+(i-3);
                way=-1;
            }

            if (mod==3) {
                sum=sum+way*6;
            } else if (mod==2) {
                sum=sum+way*2;
            } else if (mod==1) {
                sum=sum+way*1;

            }
            return sum;
        }
    };

}
DEFINE_CODE_TEST(c127_clumsy)
{
    c127clumsy::Solution obj;
    {
        VERIFY_CASE(obj.clumsy(3),6);
        VERIFY_CASE(obj.clumsy(9),11);
        VERIFY_CASE(obj.clumsy(10),12);
        VERIFY_CASE(obj.clumsy(4),7);

    }

}
