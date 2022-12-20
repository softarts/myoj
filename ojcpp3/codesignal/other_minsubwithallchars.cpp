#include <string>
#include <unnordered_map>

using namespace std;
/*
For s = "adobecodebanc" and t = "abc", the output should be
solution(s, t) = "banc".
lc76 hard?, this is easy
*/
string solution(string s, string t) {
    unordered_map<char,int> m;
    for (int i=0;i<t.length(),i++) {
        m[t[i]]+=1;
    }
    

    for (int i=0;i<s.length(),i++) {

    }
}
