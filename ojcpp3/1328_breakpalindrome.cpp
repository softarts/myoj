#include <string>
using namespace std;

/*
abccba=> a`a` ccba
a=> ""
这题目没有太大意思，不适合面试
*/
class Solution {
public:
    // 这个更简单，不需要考虑太多选项
    // non 'a' => a
    // 否则最后一个改成b    
    string breakPalindrome(string palindrome) {  
        string &s = palindrome;
        int n=s.size();
        if(n<=1) return "";    //if size is 1 , then it is always a palindrome
        for(int i=0;i<n/2;++i){ // 这里正好避过了 aba 中的b, 只有中线才影响。
            if(s[i]!='a'){  //replace the first non 'a' character
                s[i]='a';
                return s;
            }
        }
        s.pop_back();  //if the string is all a's => "aaaaa", then replace the last character with 'b'
        s+='b';
        return s;
    }

    // 这个做法是
    string breakPalindrome0(string palindrome) {  
        string &s=palindrome;
        auto isPalindrome=[](string &str){
            string ori=str;
            reverse(str.begin(),str.end());
            return str==ori;
        };

        int n=palindrome.length();
        if (n==1) return "";

        for (int i=0;i<n;i++) {
            for (int j=0; j< s[i]-'a';j++) {
                char c='a'+j;
                char oric=s[i];
                s[i]=c;                
                if (!isPalindrome(s)) {
                    s[i]=oric;continue;
                } else {
                    return s;
                }
            }
        }

        for (int i=n-1;i>=0;i++) {
            for (int j=s[i]-'a'+1;j<='z';j++) {
                char c='a'+j;
                char oric=s[i];
                s[i]=c;                
                if (!isPalindrome(s)) {
                    s[i]=oric;continue;
                } else {
                    return s;
                }
            }
        }

        return "";

        //

    }
};