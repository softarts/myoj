//
// Created by Rui Zhou on 12/3/18.
//

/*
 * https://leetcode.com/problems/reverse-string/description/
 * Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

 char * reverse(const char*) ?
 not allow new

 */

#include <codech/codech_def.h>
#include <string>
#include <iostream>


using namespace std;

class Solution {
public:
    string reverseString(string s) {
        if (s.empty())
            return s;
        char *begin = &s[0];
        char *end = &s[s.length()-1];
        while (begin<end) {
            std::swap(*begin,*end);
            begin++;end--;
        }
        return s;
    }
};


DEFINE_CODE_TEST(344_reverseatring)
{
    Solution obj;
    cout << obj.reverseString("hello");
}