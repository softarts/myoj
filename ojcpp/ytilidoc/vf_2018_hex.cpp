//
// Created by rui.zhou on 4/1/2019.
//

/*
 * // you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <sstream>
using namespace std;

string solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    std::stringstream stream;
    stream << std::hex << 257;
    std::string result( stream.str() );
    return result;
}

int main()
{
    string s=string("257");
    cout<<solution(s);
}

 def solution(S):
    # write your code in Python 3.6
    hexstr = "%X" % int(S)
    encode = {'1':'I','0':'O','A':'A','B':'B','C':'C','D':'D','E':'E','F':'F'}

    lst = list(hexstr)
    #print(lst)
    result = []
    for c in lst:
        if c in encode:
            result.append(encode[c])
        else:
            #print(c)
            return "ERROR"

    return ''.join(result)

if __name__=="__main__":
    print(solution(257)=="IOI")
    print(solution(3)=="ERROR")

    刚刚在Hired 上收到了Virtu Financial的邀请，楼主特别开心就做了OA。一共是五道题，一看所有的题还都不难。是codility。有一道题是问篮子里能放多少苹果，给你一个数组，0的位置是篮子已经有的重量，剩下的是每个苹果。贪心就可以了。
还有一道题十进制转换成八进制，所有的1可以变成I， 所有的0可以变成O，如果只含有字母，就输出，否则输出error，比如25A，就是EEROR，101，就是IOI。
另外一道题是给你一个数组，比如[6,2,3,4]，如果一个数比左右的都小，就变大一个，比左右的都大就变小一个。直到不变为止。收尾两个数不能动。
[6,2,3,4]就变成[6,3,3,4] [1,6,3,4,3,5] 就变成[1,5,4,4,4,5]
忘了一题。
最后一道题稍微难一点点，也不难。就是给你一个字符串，比如zzzyz，那么他的只包含相同字母子串有多少个，比如"zzz&quo
 给一个int A, 求A最少变化多少步可以变成一个斐波那契数，每次变化可以加1或者减1。其实就是求与A离得最近的那个斐波那契数与A的差值。
 */

#include <codech/codech_def.h>

namespace {

}