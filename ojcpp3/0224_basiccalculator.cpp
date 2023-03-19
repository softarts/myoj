#include <string>
#include <ctype.h> //isdigit
#include <stack>
#include <iostream>

using namespace std;
/*
1+1
1-2+1
(1+(4+5+2)-3)+(6+8)
整体思路
这里没有明显分割符，只能逐个解释,
首先要解释数字
sign默认是+1, 遇到-之后变成-1 *sign
遇到(将当前的sum和sign入栈, 遇到) 出栈

*/
class Solution {
public:
    int calculate(string s) {
        long sum=0;
        int sign=+1;
        stack<pair<int, int>> st;
        for (int i=0;i<s.length();i++) {
            char ch=s[i];
            if (isdigit(ch)) {
                long num=0;
                while (i<s.length() && isdigit(s[i])) {
                    num=num*10+s[i]-'0';
                    i++;
                }
                i--; // back one step;
                sum+=num*sign; // 与上次的sum累加
                sign=+1;  // reset
            } else if (ch=='(') {
                //push to stack
                st.push(pair(sum,sign));
                sum=0;
                sign=+1;
            } else if (ch==')') {
                // calculate
                sum=st.top().first + st.top().second*sum;
                st.pop();
            } else if (ch=='-') {
                sign=-1*sign; // 处理 6 - -5这种情况
            }
        }
        return sum;        
    }
};

int main() {
    Solution obj;
    int actual = obj.calculate("1+2-3");
    cout << boolalpha << (actual)<<endl;
}