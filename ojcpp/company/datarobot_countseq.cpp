//
// Created by rui.zhou on 2019/9/11.
//
/* datarobot 最长公共子序列， 中间可以删掉1个或多个词
 * you are the apple of my eye
 * the apple of my eye you are  --->5
 * the apple you are the apple of my eye  -> 6   [the apple of my eye -->5]
 * 定义出子状态
 lc1143
 */
#include <codech/codech_def.h>
#include <iterator>
using namespace std;

namespace {
    int longestCommonSubsequence(string txt1, string txt2) {
        istringstream iss(txt1);
        vector<string> vt1;
        copy(istream_iterator<string>(iss),istream_iterator<string>(),back_inserter(vt1));
        istringstream iss2(txt2);
        vector<string> vt2{istream_iterator<string>(iss2), istream_iterator<string>()};
        vector<vector<int>> dp(vt1.size()+1, vector<int>(vt2.size()+1,0));

        for (size_t i=1;i<=vt1.size();i++) {
            for (size_t j=1;j<=vt2.size();j++) {
                if (vt1[i-1] == vt2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[vt1.size()][vt2.size()];
    }
}

DEFINE_CODE_TEST(datarobot_lcs)
{
    VERIFY_CASE(longestCommonSubsequence("you are the apple of my eye","the apple of my eye you are"),5);
    VERIFY_CASE(longestCommonSubsequence("you are the apple of my eye","the apple you are the apply of my eye"),6);
    VERIFY_CASE(longestCommonSubsequence("you are the apple of my eye","the apple of my eye you are"),5);
}
