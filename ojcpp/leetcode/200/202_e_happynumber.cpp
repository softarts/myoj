//
// Created by Zhou Rui on 12/13/2018.
//

/*
 * https://leetcode.com/problems/happy-number/
 * Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer,
 replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1
 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 Those numbers for which this process ends in 1 are happy numbers.

Example:

Input: 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
 */
#include <codech/codech_def.h>

using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        if (n<=0)
            return false;
         int sum = 0;

         while (true) {
             while (n>0) {
                 int h = n % 10;
                 sum+=h*h;
                 n = n/10;
             }
             if (s.find(sum)!=s.end()) {
                 return false;
             } else {
                 if (sum==1)
                     return true;
                 s.insert(sum);
             }
             n = sum;
             sum = 0;
         }
    }
};

DEFINE_CODE_TEST(202_happynumber)
{
    Solution obj;
    {
        VERIFY_CASE(obj.isHappy(19), true);
        VERIFY_CASE(obj.isHappy(0), false);
        VERIFY_CASE(obj.isHappy(1), true);
        VERIFY_CASE(obj.isHappy(1000), true);
        VERIFY_CASE(obj.isHappy(68), true);
        VERIFY_CASE(obj.isHappy(-68), false);
    }
}