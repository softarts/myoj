#include <codech/codech_def.h>
using namespace std;

/*
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10

2021-08-31
11:56 AM 如何加入()，???
想不出来，这解法太精彩了..分治法
分治法，当遇到+-*的时候将两边分别递归处理
A+B*C-D,将所有组合起来, 
A + (B*C-D), 
B*C-D 又可以再切分 B * (C-D)  和 (B*C) - D
*/
namespace {
    class Solution {
    public:
        vector<int> diffWaysToCompute(string expression) {
            vector<int> ret;
            for (int i=0;i<expression.size();i++) {
                if (expression[i]=='+' || expression[i]=='-' || expression[i]=='*') {
                    vector<int> left = diffWaysToCompute(expression.substr(0,i));
                    vector<int> right = diffWaysToCompute(expression.substr(i+1));
                    for (auto &l :left) {
                        for (auto &r:right) {
                            if (expression[i]=='+') {
                                ret.emplace_back(l+r);
                            } else if (expression[i]=='-') {
                                ret.emplace_back(l-r);
                            } else if (expression[i]=='*') {
                                ret.emplace_back(l*r);
                            }
                        }
                    }
                }
            }
            if (ret.empty()) {
                return {stoi(expression)};
            } else {
                return ret;
            }
        }
    };
}