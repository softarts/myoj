//
// Created by rui zhou on 04/05/19.
//

/*
 * Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

#include <codech/codech_def.h>
using namespace std;

// 考虑k非个位数的情况
// 就是递归的做法，考虑各种字符串

namespace {
    class Solution {
    public:
        string decodeString(string s) {
            int pos = 0;
            return dfs(1,s,pos);
        }

        string dfs(int repeat,string &s, int &cur) {
            if (s.empty())
                return "";
            string ret, buffer;
            int r=0;
            while (cur < s.length()) {
                if (isdigit(s[cur])) {
                    r = r*10+s[cur]-'0';
                } else if (s[cur]=='['){
                    cur++;
                    buffer+=dfs(r,s,cur);
                    r=0;
                } else if (s[cur]==']') {
                    break;
                } else {
                    buffer+=s[cur];
                }
                cur++;
            }

            for (int i=0;i<repeat;i++) {
                ret+=buffer;
            }
            return ret;
        }
    };
}

DEFINE_CODE_TEST(394_decode_string)
{
    Solution obj;
    {
        VERIFY_CASE(obj.decodeString("12[abc]"),"abcabcabcabcabcabcabcabcabcabcabcabc");
        VERIFY_CASE(obj.decodeString("3[a]2[bc]"),"aaabcbc");
        VERIFY_CASE(obj.decodeString("3[a2[c]]"),"accaccacc");
        VERIFY_CASE(obj.decodeString("2[abc]3[cd]ef"),"abcabccdcdcdef");
    }
}