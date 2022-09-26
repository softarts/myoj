//
// Created by rui.zhou on 1/24/2019.
//

/*
 * Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

//TODO use hashmap?
#include <codech/codech_def.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        return s==t;
    }
};

DEFINE_CODE_TEST(242_anagram)
{
    Solution obj;
    {
        VERIFY_CASE(obj.isAnagram("rat","car"), false);
        VERIFY_CASE(obj.isAnagram("anagram","nagaram"), true);

    }
}