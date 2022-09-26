//
// Created by rui.zhou on 3/29/2019.
//
/*
 * https://www.geeksforgeeks.org/find-number-perfect-squares-two-given-numbers/
 * Given two given numbers a and b where 1<=a<=b, find the number of perfect squares between a and b (a and b inclusive).

Examples

Input :  a = 3, b = 8
Output : 1
The only perfect in given range is 4.

Input : a = 9, b = 25
Output : 3
The three squares in given range are 9,
16 and 25
 */

#include <codech/codech_def.h>
#include <cmath>
using namespace std;
namespace {
    int solution(int a, int b)
    {
        if (a < 0)
            a = 1;  // 0?
        if (b < 0)
            return 0;

        int l = ceil(sqrt(a));   // smaller integer no less than it
        int u = sqrt(b);
        if (l > u)
            return 0;
        else
            return u - l + 1;
    }
}

DEFINE_CODE_TEST(vf1_whole_square)
{
    VERIFY_CASE(solution(4, 17), 3);
    VERIFY_CASE(solution(5, 6), 0);
    VERIFY_CASE(solution(-4, 17), 4);
    VERIFY_CASE(solution(-24, -17), 0);
}


