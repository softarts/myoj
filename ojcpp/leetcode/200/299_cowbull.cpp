#include <codech/codech_def.h>
using namespace CODECH;
using namespace std;
/*
You are playing the Bulls and Cows game with your friend.

You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

The number of "bulls", which are digits in the guess that are in the correct position.
The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

 

Example 1:

Input: secret = "1807", guess = "7810"
Output: "1A3B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1807"
  |
"7810"
Example 2:

Input: secret = "1123", guess = "0111"
Output: "1A1B"
Explanation: Bulls are connected with a '|' and cows are underlined:
"1123"        "1123"
  |      or     |
"0111"        "0111"
Note that only one of the two unmatched 1s is counted as a cow since the non-bull digits can only be rearranged to allow one 1 to be a bull.
 

Constraints:

1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret and guess consist of digits only.
*/

namespace {
    class Solution {
    public:
        string getHint(string secret, string guess) {
            int a = 0, b = 0, dict[10] = {0};
            for (int i = 0;i<guess.size();i++) {
                char g = guess[i];
                char c = secret[i];
                if (g == c) {
                    a++;
                } else {
                    // 这里很巧妙,只使用一个map来记录,一个是++,另一个是--;
                    //当++的时候，如果<=0 ,表明之前有负数，为[c]写入的
                    // -- >=0同理          
                    // int d0 = (++dict[g-'0']);
                    // cout << g-'0'<<":"<< d0 << endl;
                    // int d1 = (--dict[c-'0']);        
                    // cout << c-'0'<<":"<<d1 <<std::endl;
                    // b += d0 <=0 + d1 >=0;
                    // cout << "b:" << b << endl;
                    
                    // 这个是post inc/dec, 有点难理解
                    // b += (c[s]++ < 0) + (c[g]-- > 0);

                    b += (dict[g-'0']++ <= 0) + (dict[c-'0']-- >= 0);
                }
            }
            return to_string(a) + "A" + to_string(b) + "B";
        }
    };
}