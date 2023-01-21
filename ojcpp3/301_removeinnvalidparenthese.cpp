#include <vector>
#include <string>
using namespace std;

/*
Input: s = "()())()"
Output: ["(())()","()()()"] hard
难点，输出所有结果
1.去掉一个[1] )
2.去掉[4] )

计算多余的( 和多余的)，在每一个多余的(处都进行选择(backtracking)
*/
class Solution {
public:
    
    unordered_set<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        int left=0,right=0;
        for (int i=0;i<s.length();i++) {
            switch (s[i]) {
                case '(':
                    left++;
                break;
                case ')':
                    if (left>0) {
                        left--;
                    } else {
                        right++;
                    }
                default:
                break;
            }
        }
        helper(left, right,0,s,"");
        return vector<string>(ans.begin(),ans.end());
    }

    bool isValid(string &s) {
        int left=0,right=0;
        for (int i=0;i<s.length();i++) {
            switch (s[i]) {
                case '(':
                    left++;
                break;
                case ')':
                    if (left>0) {
                        left--;
                    } else {
                        right++;
                    }
                default:
                break;
            }
        }
        return (left==0 && right==0);
    }

    void helper(int left, int right, int pos, string &s, string cur) {
        if (pos>s.length()) return;
        if (left==0 && right==0) {
            string comb = cur+s.substr(pos);
            if (isValid(comb)) {
                ans.insert(comb);
            }
            return;
        }

        // 剪枝，避免过多的处理
        if ((s.length()-pos)>(left+right)) {
            helper(left,right,pos+1,s,cur+s[pos]);
        }
        

        if (left>0 && s[pos]=='(') {
            helper(left-1,right,pos+1,s,cur);
        }
        if (right>0 && s[pos]==')') {
            helper(left,right-1,pos+1,s,cur);
        }
    }
};