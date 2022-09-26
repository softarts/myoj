//
// Created by rui.zhou on 2/28/2019.
//

/*
 * amazon
 * https://www.lintcode.com/problem/find-substring/
 * 给定长度k，找出字符串str里面所有长为k的子串。子串的字符不能重复，输出满足这样条件的子串数量(子串相同的只算1个)。
Description
Given the length k, find all substrings of length k in the string str.
The characters of a substring can not be repeated and output the number of substrings that satisfy such conditions
(the same substring is counted only 1 times).
|str| <= 100000.
k <= 100000.
All characters are lowercase.
Example
Given str = "abc", k = 2, output 2.  ->ab ,bc
Explanation:
Characters are not repeated, and substrings of length k have "ab", "bc".
与lc003很接近，只不过这里要求正好是K的输出个数，前者是最大长度
 https://zhuanlan.zhihu.com/p/36736810
*/

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    int findSubstring(string s, int k) {
        if (k > 26) {
            return 0;
        }
        unordered_map<char,int> map;
        unordered_set<string> result;
        int start=0;
        for (int i=0; i<s.length();i++) {
            if (map.count(s[i])) {
                while (s[start]!=s[i]) {
                    map.erase(s[start]);start++;
                }
                start++;
            }
            // s[i] not in map,
            map[s[i]]=i;
            if (map.size()==k) {
                string s0=s.substr(start,i-start+1);
                result.emplace(s0);
                map.erase(s[start++]);
            }
        }
        return result.size();
    }
};

DEFINE_CODE_TEST(lint_1377_findsubstr)
{
    Solution obj;
    {
        string s="abc";
        VERIFY_CASE(obj.findSubstring(s,2),2);
    }
    {
        string s="abc";
        VERIFY_CASE(obj.findSubstring(s,1),3);
    }

    {
        string s="abcdefg";
        VERIFY_CASE(obj.findSubstring(s,4),4);
    }
    {
        string s="abcaefg";
        VERIFY_CASE(obj.findSubstring(s,4),3);
    }

    {
        string s="abc";
        VERIFY_CASE(obj.findSubstring(s,4),0);
    }



}

