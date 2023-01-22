
#include <iostream>
using namespace std;


// 假设dp[i]为以i为结尾的字符串解码方式数量的总和。
// 类似于climbstair 070?
// "12" => (1,2) & (12) ==> 2种，
// 当s[i]有效的时候 => 则dp[i] += dp[i - 1] (所以, 看到第二位(2)，dp[1] +=dp[0], dp[0]=1, 加上dp[0]的数值)
// 当s[i - 1]s[i]组成的字符串有效时(即和前一个数) => dp[i] += dp[i - 2] (dp[1] += dp[-1], dp[-1]=1)
// 排除第一位为0的异常情况
// 从index=1开始， 如果有效，则tmp+=f1;tmp+=f2,f2->f1->tmp



class Solution {
public:
    int numDecodings(string s) {        
        if (s.empty() || s[0]=='0') return 0;
        if (s.size() == 1) return 1;
        int f1 = 1, f2 = 1;
        for (int i = 1; i < s.size();i++) {
            int tmp = 0;
            if (isValid(s[i])) tmp+=f1;
            if (isValid(s[i-1],s[i])) tmp+=f2;
            if (!isValid(s[i-1],s[i]) && !isValid(s[i])) return 0;
            f2 = f1;
            f1 = tmp;
        }
        return f1;
    }
    bool isValid(char a,char b){
        return a == '1'||(a == '2' && b <='6');
    }
    bool isValid(char a){
        return a != '0';
    }    
};

int main() {
  int ret = Solution().numDecodings("12");
  cout << boolalpha << (ret==2) << endl;
  return 0;
}