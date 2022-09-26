//
// Created by rui zhou on 01/04/18.
//

/*https://leetcode.com/problems/expressive-words/
 * https://leetcode.com/contest/weekly-contest-78/problems/expressive-words/
 * Sometimes people repeat letters to represent extra feeling, such as "hello" -> "heeellooo", "hi" -> "hiiii".  Here, we have groups, of adjacent letters that are all the same character, and adjacent characters to the group are different.  A group is extended if that group is length 3 or more, so "e" and "o" would be extended in the first example, and "i" would be extended in the second example.  As another example, the groups of "abbcccaaaa" would be "a", "bb", "ccc", and "aaaa"; and "ccc" and "aaaa" are the extended groups of that string.

For some given string S, a query word is stretchy if it can be made to be equal to S by extending some groups.  Formally, we are allowed to repeatedly choose a group (as defined above) of characters c, and add some number of the same character c to it so that the length of the group is 3 or more.  Note that we cannot extend a group of size one like "h" to a group of size two like "hh" - all extensions must leave the group extended - ie., at least 3 characters long.

Given a list of query words, return the number of words that are stretchy.

Example:
Input:
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation:
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
Notes:

0 <= len(S) <= 100.
0 <= len(words) <= 100.
0 <= len(words[i]) <= 100.
S and all words in words consist only of lowercase letters
判断有多少个单词可以通过extend 来得到S字串
开始对允许2-->3这个不清楚
 // l-->ll; x
// ll-->lll ok
 */
#include <codech/codech_def.h>
using namespace std;
namespace {
    class Solution {
    public:
        int expressiveWords(string S, vector<string>& words) {
            if (S.length()==0)
                return 0;

            auto convert = [](string &txt) {
                vector<string> ret;
                char prev = txt[0];
                int begin = 0;
                for (int i=1;i<txt.length();i++) {
                    if (txt[i]!=prev) {
                        ret.push_back(txt.substr(begin, i-begin));
                        prev = txt[i];
                        begin = i;
                    }
                }
                ret.push_back(txt.substr(begin));
                return ret;
            };

            auto comp = [](vector<string> &a,vector<string> &b){
                if (a.size()!=b.size()) return false;
                for (int i=0;i<a.size();i++) {
                    if (a[i][0] != b[i][0]) return false;
                    int as = a[i].size();int bs = b[i].size();
                    if (as>bs) return false;

                    if (as!=bs) {
                        if (as>bs || bs<3) return false;
                    }
                }
                return true;
            };

            int ans = 0;
            vector<string> svec = convert(S);
            for (auto &w: words) {
                auto wvec = convert(w);
                if (comp(wvec,svec)) ans++;
            }
            return ans;
        }
    };
}

DEFINE_CODE_TEST(809_expressive_word)
{
    Solution obj;
    {
        vector<string> words{"dinnssoo","ddinso","ddiinnso","ddiinnssoo","ddiinso","dinsoo","ddiinsso","dinssoo","dinso"};
        VERIFY_CASE(obj.expressiveWords("dddiiiinnssssssoooo",words),3);
    }
    {
        vector<string> words{"aaaa"};
        VERIFY_CASE(obj.expressiveWords("aaa",words),0);
    }

    {
        vector<string> words{"zzyy","zy","zyy"};
        VERIFY_CASE(obj.expressiveWords("zzzzzyyyyy", words),3);
    }
    {
        vector<string> words{"abc"};
        VERIFY_CASE(obj.expressiveWords("abcd", words),0);
    }


    {
        vector<string> words{"hello", "hi", "helo"};
        VERIFY_CASE(obj.expressiveWords("heeellooo",words),1);
    }

}
