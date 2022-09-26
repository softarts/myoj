//
// Created by rui.zhou on 10/3/2019.
//

/*
 * We are given a personal information string S, which may represent either an email address or a phone number.

We would like to mask this personal information according to the following rules:


1. Email address:

We define a name to be a string of length ≥ 2 consisting of only lowercase letters a-z or uppercase letters A-Z.

An email address starts with a name, followed by the symbol '@', followed by a name, followed by the dot '.' and followed by a name.

All email addresses are guaranteed to be valid and in the format of "name1@name2.name3".

To mask an email, all names must be converted to lowercase and all letters between the first and last letter of the first name must be replaced by 5 asterisks '*'.


2. Phone number:

A phone number is a string consisting of only the digits 0-9 or the characters from the set {'+', '-', '(', ')', ' '}. You may assume a phone number contains 10 to 13 digits.

The last 10 digits make up the local number, while the digits before those make up the country code. Note that the country code is optional. We want to expose only the last 4 digits and mask all other digits.

The local number should be formatted and masked as "***-***-1111", where 1 represents the exposed digits.

To mask a phone number with country code like "+111 111 111 1111", we write it in the form "+***-***-***-1111".  The '+' sign and the first '-' sign before the local number should only exist if there is a country code.  For example, a 12 digit phone number mask should start with "+**-".

Note that extraneous characters like "(", ")", " ", as well as extra dashes or plus signs not part of the above formatting scheme should be removed.



Return the correct "mask" of the information provided.



Example 1:

Input: "LeetCode@LeetCode.com"
Output: "l*****e@leetcode.com"
Explanation: All names are converted to lowercase, and the letters between the
             first and last letter of the first name is replaced by 5 asterisks.
             Therefore, "leetcode" -> "l*****e".
Example 2:

Input: "AB@qq.com"
Output: "a*****b@qq.com"
Explanation: There must be 5 asterisks between the first and last letter
             of the first name "ab". Therefore, "ab" -> "a*****b".
Example 3:

Input: "1(234)567-890"
Output: "***-***-7890"
Explanation: 10 digits in the phone number, which means all digits make up the local number.
Example 4:

Input: "86-(10)12345678"
Output: "+**-***-***-5678"
Explanation: 12 digits, 2 digits for country code and 10 digits for local number.
Notes:

S.length <= 40.
Emails have length at least 8.
Phone numbers have length at least 10.
 一道无聊的题目，来自国内，主要是对规则的判断
 */
#include <codech/codech_def.h>
#include <numeric>
using namespace std;
namespace {
    class Solution {
    public:
        string maskPII(string S) {
            size_t pos = S.find_first_of("@");
            std::transform(S.begin(),S.end(),S.begin(),::tolower);
            unordered_set<char> ignore{'+', '-', '(', ')', ' '};
            if (pos!=string::npos) { // email
                string name = S.substr(0,pos);
                string domain = S.substr(pos);
                string ret1 = string(1,tolower(name[0]));
                string ret2 = string(1,tolower(name[name.size()-1]));
                string ret3 = ret1+"*****"+ret2+domain;
                return ret3;
            } else {
                size_t count = std::accumulate(S.begin(),S.end(),0,[](int sum, char b){
                    sum+=isdigit(b)?1:0;
                    return sum;
                });
                int last4 = 0;
                string number = "";
                for (auto riter=S.rbegin();riter!=S.rend();++riter) {
                    if (ignore.count(*riter)==0) {
                        number.push_back(*riter);
                        if (++last4 == 4)
                            break;
                    }
                }
                reverse(number.begin(),number.end());
                number =  "***-***-" + number;

                if (count==10) return number;
                else if (count==11) return "+*-"+number;
                else if (count==12) return "+**-"+number;
                else if (count==13) return "+***-"+number;
            }
            return "";
        }
    };
}

DEFINE_CODE_TEST(831_maskpersonalinfo) {
    Solution obj;
    {
        VERIFY_CASE(obj.maskPII("1(234)567-890"),"***-***-7890");
        VERIFY_CASE(obj.maskPII("LeetCode@LeetCode.com"),"l*****e@leetcode.com");
        VERIFY_CASE(obj.maskPII("86-(10)12345678"),"+**-***-***-5678");


    }
}