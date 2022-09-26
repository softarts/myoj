//
// Created by rui zhou on 15/04/18.
//

/*
 * https://leetcode.com/problems/most-common-word/
 * https://leetcode.com/contest/weekly-contest-80/problems/most-common-word/
 * Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.

Example:
Input:
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.


Note:

1 <= paragraph.length <= 1000.
1 <= banned.length <= 100.
1 <= banned[i].length <= 10.
The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
Different words in paragraph are always separated by a space.
There are no hyphens or hyphenated words.
Words only consist of letters, never apostrophes or other punctuation symbols.
 */

#include <codech/codech_def.h>
using namespace std;

const int dictSize = 256;

vector<string> tokenizeMyString(const string &s, const string &del)
{
    static bool dict[dictSize] = { false};

    vector<string> res;
    for (int i = 0; i < del.size(); ++i) {
        dict[del[i]] = true;
    }

    string token("");
    for (auto &i : s) {
        if (dict[i]) {
            if (!token.empty()) {
                res.push_back(token);
                token.clear();
            }
        }
        else {
            token += i;
        }
    }
    if (!token.empty()) {
        res.push_back(token);
    }
    return res;
}


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> mc;
        int maxcount = 0;
        string maxstr = "";
        //the delimiters are " " (space) and "," (comma)
        vector<string> splitpara = tokenizeMyString(paragraph, "!?',;. ");
        for (auto &iter:splitpara) {
            if (ban.find(iter)==ban.end()) {
                mc[iter] += 1;
                if (mc[iter] > maxcount) {
                    maxcount = mc[iter];
                    maxstr = iter;
                }
            }
        }
        return maxstr;
    }
};

DEFINE_CODE_TEST(819_mostcommonword)
{
    Solution obj;
    {
        string s = "Bob hit a ball, the hit BALL flew far after it was hit.";
        vector<string> banned{"hit"};
        VERIFY_CASE(obj.mostCommonWord(s, banned),"ball");
    }
}

