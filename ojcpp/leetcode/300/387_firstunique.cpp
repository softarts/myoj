//
// Created by Rui Zhou on 13/3/18.
//

/*
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 * Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

 5:30pm->
amazon
 */

#include <codech/codech_def.h>
#include <string>
//#include <unordered_set>
#include <array>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        std::array<int, 26> arr = {};

        for (int i=0;i<s.length();i++) {
            int idx = s[i] - 'a';
            arr[idx]+=1;
        }

        for (int i=0;i<s.length();i++) {
            int idx = s[i] - 'a';
            if (arr[idx]==1)
                return i;
        }
        return -1;
    }
};



DEFINE_CODE_TEST(387_firstuniquechar)
{
    Solution obj;
    VERIFY_CASE(obj.firstUniqChar("leetcode"), 0)
    VERIFY_CASE(obj.firstUniqChar("loveleetcode"), 2)
}