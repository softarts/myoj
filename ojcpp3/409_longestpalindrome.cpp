#include <string>
using namespace std;
/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
*/

#include <unordered_set>

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> m;
        int ans=0;
        for (int i=0;i<s.length();i++) {
            if (!m.count(s[i])) {
                m.insert(s[i]);
            } else {
                ans+=2;
                m.erase(s[i]);
            }
        }
        if (!m.empty()) {
            ans+=1;
        }
        return ans;
    }
};