/*
Input: s = "abacaba"
Output: 2
Explanation: There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
"ab" is the longest continuous substring.

找出符合字母顺序的最长子序列
1:42-1:47 这是啥烂题，只值easy
*/

#include <string>
using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=1;
        int cursub=1;
        for (int i=1;i<s.length();i++) {
            if (s[i]-s[i-1]==1) {
                cursub++;
            } else {
                cursub=1;
            }
            ans = max(ans, cursub);
        }
        return ans;
    }
};