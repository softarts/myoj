/*
Also simple idea why digital root equals to mod 9 if we've got an ABCD number
ABCD = 1000A+100B+10*C+D = (A + B + C + D) + 9 * (111 * A + 11 * B + C)
this equals (mod 9) to A + B + C + D.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // 利用上面的结论
        if (num==0) return 0;
        if (num%9==0) return 9;
        return num%9;
    }
};