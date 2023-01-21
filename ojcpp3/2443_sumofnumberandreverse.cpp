#include <string>
using namespace std;
// 用string 超时
class Solution {
public:
    int reverseDigits(int num) {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }

    bool sumOfNumberAndReverse(int num) {
        for (int i=0;i<=num;i++) {
            // string rs = to_string(i);
            // reverse(rs.begin(),rs.end());
            // int r = stoi(rs);
            int r = reverseDigits(i);
            if (i+r==num) return true; 
        }
        return false;
    }
};