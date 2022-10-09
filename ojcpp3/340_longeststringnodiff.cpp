
/*
 * amazon
 * lc340 hard
 * lint 386
 * https://www.lintcode.com/problem/longest-substring-with-at-most-k-distinct-characters/description
 * Given a string S, find the length of the longest substring T that contains at most k distinct characters.

Example
Example 1:

Input: S = "eceba" and k = 3
Output: 4
Explanation: T = "eceb"
Example 2:

Input: S = "WORLD" and k = 4
Output: 4
Explanation: T = "WORL" or "ORLD"
Challenge
O(n) time
 */

#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int ans=0;
        unordered_map<char,int> m;
        int start=0;
        for (int i=0;i<s.length();i++) {
            m[s[i]]++;
            while (m.size()>k) {
                char c=s[start];
                if (--m[c]==0) {
                    m.erase(c);
                }
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};



int main() {
    Solution obj;
    {
        string s="eceba";
        cout << boolalpha << (obj.lengthOfLongestSubstringKDistinct(s,3) == 4) << endl;
    }

    {
        string s="WORLD";
        cout << boolalpha << (obj.lengthOfLongestSubstringKDistinct(s,4) == 4) << endl;
    }
}
