//
// Created by rui zhou on 25/03/18.
//

/*
 * https://leetcode.com/contest/weekly-contest-77/problems/number-of-lines-to-write-string/
 * We are to write the letters of a given string S, from left to right into lines. Each line has maximum width 100 units, and if writing a letter would cause the width of the line to exceed 100 units, it is written on the next line. We are given an array widths, an array where widths[0] is the width of 'a', widths[1] is the width of 'b', ..., and widths[25] is the width of 'z'.

Now answer two questions: how many lines have at least one character from S, and what is the width used by the last such line? Return your answer as an integer list of length 2.



Example :
Input:
widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "abcdefghijklmnopqrstuvwxyz"
Output: [3, 60]
Explanation:
All letters have the same length of 10. To write all 26 letters,
we need two full lines and one line with 60 units.
Example :
Input:
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
S = "bbbcccdddaaa"
Output: [2, 4]
Explanation:
All letters except 'a' have the same length of 10, and
"bbbcccdddaa" will cover 9 * 10 + 2 * 4 = 98 units.
For the last 'a', it is written on the second line because
there is only 2 units left in the first line.
So the answer is 2 lines, plus 4 units in the second line.


Note:

The length of S will be in the range [1, 1000].
S will only contain lowercase letters.
widths is an array of length 26.
widths[i] will be in the range of [2, 10].
 */


#include <codech/codech_def.h>
#include <vector>
#include <string>
#include <codech/algo_common.h>

using namespace std;
using namespace CODECH;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lineWidth = 0;
        int lines = 0;
        for (int i=0;i<S.length();i++) {
            int lastWidth = widths[S[i]-'a'];
            if (lineWidth + lastWidth > 100) {
                lines++;
                lineWidth = lastWidth;
            } else {
                lineWidth+=lastWidth;
            }
        }
        if (lineWidth>0)
            return vector<int>({lines+1, lineWidth});
        else
            return vector<int>({lines, lineWidth});
    }
};


DEFINE_CODE_TEST(806_numberofline_to_writestring)
{
    Solution obj;
    {
        vector<int> nums{10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        string s="abcdefghijklmnopqrstuvwxyz";
        VERIFY_CASE(PRINT_VEC(obj.numberOfLines(nums, s)),"3 60");
    }

    {
        vector<int> nums{4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        string s = "bbbcccdddaaa";
        VERIFY_CASE(PRINT_VEC(obj.numberOfLines(nums, s)),"2 4");
    }
    {
        vector<int> nums{7,5,4,7,10,7,9,4,8,9,6,5,4,2,3,10,9,9,3,7,5,2,9,4,8,9};
        string s = "zlrovckbgjqofmdzqetflraziyvkvcxzahzuuveypqxmjbwrjvmpdxjuhqyktuwjvmbeswxuznumazgxvitdrzxmqzhaaudztgie";
        VERIFY_CASE(PRINT_VEC(obj.numberOfLines(nums, s)),"7 69");
    }
}
