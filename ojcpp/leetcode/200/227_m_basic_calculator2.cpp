//
// Created by rui.zhou on 3/16/2019.
//

/*
 * Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
 4:21pm
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int calculate(string s) {
            int64_t num=0;
            int64_t add_res=0,mult_res=1,mult_sign=1,add_sign=1;
            for (int i=0;i<s.length();i++) {
                if (s[i]>='0' && s[i]<='9') {
                    num=num*10+s[i]-'0';
                } else if (s[i]!=' '){
                    mult_res=mult_sign==1? mult_res*num:mult_res/num;
                    //同时可以适用于+/-,即每遇到一个非空字符，必须将之前的*/结果计算出来
                    num=0;
                    if (s[i]=='+' || s[i]=='-') {
                        add_res+= add_sign*mult_res;
                        add_sign = s[i] == '+' ? 1 : -1;
                        mult_res = 1; mult_sign = 1;//mult_res=1很关键，适用于*和+-
                    } else if (s[i]=='*' || s[i]=='/') {
                        mult_sign = s[i] == '*' ? 1 : -1;
                    }
                }
            }
            return add_res + add_sign*(mult_sign==1? mult_res*num:mult_res/num);
            //return add_res + add_sign * (mult_sign == 1 ? mult_res * num : mult_res / num);
        }
    };
}

DEFINE_CODE_TEST(227_basic_calculator2)
{
    Solution obj;
    {
        VERIFY_CASE(obj.calculate("42"),42);
        VERIFY_CASE(obj.calculate("3+2*2"),7);
        VERIFY_CASE(obj.calculate("3/2"),1);
        VERIFY_CASE(obj.calculate("3+2*2+4"),11);

    }
}