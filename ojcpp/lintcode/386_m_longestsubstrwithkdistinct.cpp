//
// Created by rui.zhou on 2/28/2019.
//

/*
 * amazon
 * lc340 hard
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

#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if (k>s.length())
            return s.length();
        int maxLen=INT_MIN;
        int start=0;
        unordered_map<char,int> map;
        for (int i=0;i<s.length();i++) {
            map[s[i]]+=1;
            while (map.size()>k) {
                map[s[start]]-=1;
                if (map[s[start]]==0) {
                    map.erase(s[start]);
                }
                start++;
            }
            maxLen = max(maxLen,i-start+1);
        }
        return maxLen;
    }
};

DEFINE_CODE_TEST(386_longestsubstrkdistinct)
{
    Solution obj;
    {
        string s="eceba";
        VERIFY_CASE(obj.lengthOfLongestSubstringKDistinct(s,3),4);
    }
    {
        string s="eceba";
        VERIFY_CASE(obj.lengthOfLongestSubstringKDistinct(s,1),1);
    }

    {
        string s="eceba";
        VERIFY_CASE(obj.lengthOfLongestSubstringKDistinct(s,6),5);
    }
    {
        string s="WORLD";
        VERIFY_CASE(obj.lengthOfLongestSubstringKDistinct(s,4),4);
    }

}

