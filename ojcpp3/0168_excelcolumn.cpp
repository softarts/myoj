#include <iostream>
using namespace std;

//A,B,C...Z,AA,AB,AC..ZZ,AAA,已知A=1，求出AAA为多少 lc168?
// AA -> 27 -> 1(26) + 1 = 27
// 与10进制不同，这里没有0，26->Z,27->AA
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        int n = columnNumber;
        char tbl[27];
        for (int i=1;i<27;i++) {
            tbl[i] = 'A'+i-1;
        }
        tbl[0]='Z';
        
        while (n>0) {
            ans+=tbl[n%26];
            n=(n-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};