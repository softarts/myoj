//
// Created by rui zhou on 29/04/18.
//

/*
 * https://leetcode.com/contest/weekly-contest-82/problems/goat-latin/
 * A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.

 Example 1:

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
 */

#include <codech/codech_def.h>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        vector<string> output;
        stringstream input_stringstream(S);
        string token;

        string a = "a";
        while (getline(input_stringstream,token,' '))
        {
            if (!output.empty())
                output.emplace_back(" ");
            char c = tolower(token[0]);
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                token += "ma" + a;
            } else {
                token = token.substr(1) + token[0] + "ma" + a ;
            }
            a += "a";
            output.emplace_back(token);
        }
        std::string ret = std::accumulate(output.begin(), output.end(), std::string(""));
        return ret;
    }
};


DEFINE_CODE_TEST(824_goatlatin)
{
    Solution obj;
    {
        VERIFY_CASE(obj.toGoatLatin("I speak Goat Latin"),"Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
    }

    {
        VERIFY_CASE(obj.toGoatLatin("The quick brown fox jumped over the lazy dog"),"heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa");
    }

}

