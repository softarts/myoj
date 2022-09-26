//
// Created by rui zhou on 10/05/19.
//
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int add(int num1,int num2) {
            int sum,carry;
            do {
                sum=num1^num2;
                carry = (num1&num2)<<1;
                num1 = sum;
                num2=carry;
            }while (num2!=0);
            return num1;
        }
    };
}