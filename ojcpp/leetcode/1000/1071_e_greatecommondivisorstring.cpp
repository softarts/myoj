//
// Created by rui.zhou on 9/30/2019.
//

/*
 * For strings S and T, we say "T divides S" if and only if S = T + ... + T  (T concatenated with itself 1 or more times)

Return the largest string X such that X divides str1 and X divides str2.



Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
8:49
找出两个字符串共有的最大子字符串
 ABABCDEF, ABAB
 参考 amazon gcd的做法
GCD a
 */
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:

        string gcdOfStrings(string str1, string str2) {
            if (str1==str2)
                return str2;
            if (str1.length()<str2.length())
                return gcdOfStrings(str2, str1);

            if (str1.substr(0,str2.length())==str2) {
                string as = str1.substr(str2.length());
                return gcdOfStrings(as, str2);
            } else {
                return "";
            }
        }
    };
}

DEFINE_CODE_TEST(1071_greate_common_divisor_string) {
    Solution obj;
    {
        VERIFY_CASE(obj.gcdOfStrings("ABABAB","ABAB"), "AB");
        VERIFY_CASE(obj.gcdOfStrings("ABCABC","ABC"), "ABC");
        VERIFY_CASE(obj.gcdOfStrings("LEET","CODE"), "");
    }
}
