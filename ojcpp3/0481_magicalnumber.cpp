//#include 
/*
A magical string s consists of only '1' and '2' and obeys the following rules:

The string s is magical because concatenating the number of contiguous occurrences of characters '1' and '2' generates the string s itself.
The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and the occurrences of 1's or 2's in each group are "1 2 2 1 1 2 1 2 2 1 2 2 ......". You can see that the occurrence sequence is s itself.

Given an integer n, return the number of 1's in the first n number in the magical string s.
Input: n = 6
Output: 3
Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.

据观察，规律为 122
然后看最后的数字2=>2个数字，为1(与2不同)

*/
#include <string>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s="122";
        if (n<=3) {
            return 1;
        }
        int idx=2;
        int ans=1;
        while (idx<n) {
            if (s[idx]=='2') {
                if (s.back()=='2') {
                    s+="11";    
                } else {
                    s+="22";
                }
            } else {  // it is 1
                if (s.back()=='2') {
                    s+="1";    
                } else {
                    s+="2";
                }
                ans++;
            }
            idx++;
        }
        return ans;
    }
};