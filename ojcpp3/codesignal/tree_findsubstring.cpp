#include <vector>
#include <string>
using namespace std;

/*
LC1032
https://leetcode.com/problems/stream-of-characters/

For words = ["Apple", "Melon", "Orange", "Watermelon"] and parts = ["a", "mel", "lon", "el", "An"], the output should be
solution(words, parts) = ["Apple", "Me[lon]", "Or[a]nge", "Water[mel]on"].
判断parts匹配哪个word

暴力法 TLE 猜测 O(M*N* len(words)) 的复杂度
使用trie 优化=>熟练使用trie 会将搜索转化为layer 层数
*/
//
vector<string> solution(vector<string> words, vector<string> parts) {
    vector<string> ans;
    for (auto &s:words) {
        string matched;
        int matchedPos;
        for (auto &p:parts) {
            int pos=s.find(p);
            if (pos!=std::string::npos) {
                if (p.length() > matched.length()) {
                    matched = p;
                    matchedPos = pos;
                } else if (p.length() == matched.length()){
                    if (pos < matchedPos) {
                        matched = p;
                        matchedPos = pos;
                    }
                }
            }
        }
        if (!matched.empty()) {
            auto lpos = matchedPos;
            auto rpos = lpos+matched.length();            
            ans.push_back(s.substr(0,lpos) +"["+matched+"]"+s.substr(rpos));        
        } else {
            ans.push_back(s);
        }
    }
    return ans;
}

