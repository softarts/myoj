//
// Created by rui zhou on 11/03/19.
//

/* greedy
 * Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,0000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

subsequence的意思是可以删除部分字符得到这个
 */

#include <codech/codech_def.h>
using namespace std;

namespace lc392 {
    class Solution {
    public:
        bool isSubsequence(string s, string t) {
            if (s.empty())
                return true;
            int cur=0;
            for (int i=0;i<t.length();i++) {
                if (t[i]==s[cur]) cur++;
                if (cur==s.length())
                    break;
            }
            return cur==s.length();
        }
    };
}


DEFINE_CODE_TEST(392_isseq)
{
    lc392::Solution obj;
    {
        VERIFY_CASE(obj.isSubsequence("abc","ahbgdc"),true);
        VERIFY_CASE(obj.isSubsequence("axc","ahbgdc"),false);
    }

}