//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/sum-of-two-integers/description/
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
 */

#include <codech/codech_def.h>

class Solution {
public:
    // too complicated.
    int getSum(int c, int d) {
        uint32_t a = c;
        uint32_t b = d;
        int prev = 0;
        int carry = 0;
        int bit = 0;
        while (a || b) {
            int r = 0;
            if ((a&b & 0x1) == 1) {  // both are 1
                if (carry==1) {
                    r = 1;
                } else {
                    r = 0;carry=1;
                }
            } else if (((a|b) & 0x1) == 1) { // one is 1
                if (carry==1) {
                    r = 0;
                } else {
                    r = 1;
                }
            } else {
                if (carry == 1) {
                    r = 1;carry=0;
                } else {
                    r = 0;
                }
            }
            prev = r<<bit|prev;bit++;
            a= a >> 1;
            b= b >> 1;
        }

        if (carry == 1 && bit <32) {
            prev = 1<<bit|prev;
        }
        return prev & 0xffffffff;
    }
};

DEFINE_CODE_TEST(371_twosum)
{
    Solution obj;
    VERIFY_CASE(obj.getSum(-1,1),0);
    VERIFY_CASE(obj.getSum(13,5),18);
    VERIFY_CASE(obj.getSum(5,5),10);
    VERIFY_CASE(obj.getSum(1,1),2);
    VERIFY_CASE(obj.getSum(1,2),3);
    VERIFY_CASE(obj.getSum(1,0),1);
    VERIFY_CASE(obj.getSum(0,0),0);


}



