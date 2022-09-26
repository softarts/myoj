//
// Created by rui zhou on 2019-09-11.
//

/*https://leetcode.com/problems/longest-common-subsequence/
 * Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.


 If there is no common subsequence, return 0.



Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.


Constraints:

1 <= text1.length <= 1000
1 <= text2.length <= 1000
The input strings consist of lowercase English characters only.

 参见datarobot
最长公共字串，中间可以不连续
问题转化为dp[0...i][0..j]是否存在公共字串
1.text1[i]==text2[j] && dp[i-1][j-1]存在公共字串
2.max(dp[i-1][j], dp[i][j-1]);

 */

#include <codech/codech_def.h>
using namespace std;

namespace {
    class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
           int dp[1001][1001] = {0};
           for (int i=1; i <=text1.length();i++) {
               for (int j=1;j<=text2.length();j++) {
                   dp[i][j] = text1[i-1]==text2[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
               }
           }
           return dp[text1.length()][text2.length()];
        }
    };
}

DEFINE_CODE_TEST(1143_longest_common_subsequence) {
    Solution obj;
    {
        VERIFY_CASE(obj.longestCommonSubsequence("abcde","ace"), 3);
        VERIFY_CASE(obj.longestCommonSubsequence("abc","abc"), 3);
        VERIFY_CASE(obj.longestCommonSubsequence("abc","def"), 0);
    }
}
