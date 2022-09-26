//
// Created by rui zhou on 07/02/19.
//

/*
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
 * Find the length of the longest substring T of a given string (consists of lowercase letters only)
 * such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 思路
 */
#include <codech/codech_def.h>
using namespace std;

class Solution {
public:
    // 方法直接废掉, 无法解决那些中间被断开的情况
    int longestSubstring0(string s, int k) {
        unordered_map<char,int> map;
        for (auto c : s) {
            map[c]+=1;
        }
        int ml = 0;
        int start=0;
        for (int i=0;i<s.length();i++) {
            if (map[s[i]]<k) {
                ml = max(ml,i-start);
                start = i+1;
            } else if (i==s.length()-1){
                ml = max(ml,i-start+1);
            }
        }
        return ml;
    }
    int longestSubstring(string s, int k) {
        return helper(s,0,s.length()-1,k);
    }

    int helper(string &s, int l, int r, int k) {
        unordered_map<char,int> map;
        for (int i=l;i<=r;i++) {
            map[s[i]]+=1;
        }

        bool pass = true;
        for (auto iter:map) {
            char c = iter.first;
            if (map[c]<k) {
                pass = false;
                break;
            }
        }
        if (pass) {
            return r-l+1;
        }

        int ans = 0;
        for (int j=l;j<=r;j++) {
            if (map[s[j]]<k) {  //split
                ans = max(ans, helper(s, l, j - 1, k));
                ans = max(ans, helper(s, j + 1,r, k));
                break;
            }
        }
        return ans;
    }
};

DEFINE_CODE_TEST(395_longestsubstrkrepeat)
{
    Solution obj;
    {
        string s="aaabb";
        VERIFY_CASE(obj.longestSubstring(s,3),3);
    }
    {
        string s="ababbc";
        VERIFY_CASE(obj.longestSubstring(s,2),5);
    }
    {
        string s="ababbc";
        VERIFY_CASE(obj.longestSubstring(s,0),6);
    }
    {
        string s="ababbc";
        VERIFY_CASE(obj.longestSubstring(s,1),6);
    }
    {
        string s="ababbcaaaaaa";
        VERIFY_CASE(obj.longestSubstring(s,2),6);
    }
    {
        string s="ababacb";
        VERIFY_CASE(obj.longestSubstring(s,3),0);
    }
}