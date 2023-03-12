#include <string>
#include <climit>
using namespace std;
/*
leetcode 159 lock,
lintcode 928

给定一个字符串，找出最长子串TT的长度，它最多包含2个不同的字符。
样例
样例 1
输入: “eceba”
输出: 3
解释:
T 是 "ece" 它的长度是 3.
5:02
*/
class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        int ans=0;
        unordered_map<char,int> m;
        int start=0;
        for (int i=0;i<s.length();i++) {
            m[s[i]]++;
            while (m.size()>2) {
                char c=s[start];
                if (--m[c]==0) {
                    m.erase(c);
                }
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};
