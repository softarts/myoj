//
// Created by rui.zhou on 2/24/2019.
//

/* CCI 6th p102
 * String Rotation:Assumeyou have a method isSubstringwhich checks if one word is a substring
of another. Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one
call to isSubstring(e.g.,"waterbottle"is a rotation of"erbottlewat").
Hints:#34,#88, # 704
 这个思路太酷了,对于移位问题必然可以将str2作为(str1+str1)的substr
 *
 */

#include <codech/codech_def.h>
using namespace std;

bool rightRotation(string a, string b) {
    if (a.empty() || b.empty() || a.size() != b.size())
        return false;
    string x = a + a;
    return (x.find(b) != string::npos);
}

DEFINE_CODE_TEST(amazon_rightrotation)
{
    VERIFY_CASE(rightRotation("abcd","cdab"),true);

}

