/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
使用栈
*/
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto &c: s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    st.push(c);
                    break;
                case ']': if (st.empty() || !st.empty() && st.top()!='[') return false; else  st.pop(); break;
                case ')': if (st.empty() || !st.empty() && st.top()!='(') return false; else  st.pop(); break;
                case '}': if (st.empty() || !st.empty() && st.top()!='{') return false; else  st.pop(); break;
            }
        }
        return st.empty();
    }
};


int main() {
    return 0;
}