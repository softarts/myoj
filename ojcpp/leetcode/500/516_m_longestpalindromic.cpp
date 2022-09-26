/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

这种求最大回文子序列的通常是dp问题,但如何构造子问题?
dp[i][j]是最长子序列？
s[i]=s[j], 正常途径
s[i]!=s[j],
*/
#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int longestPalindromeSubseq(string s) {
            vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));

        }
    };
}