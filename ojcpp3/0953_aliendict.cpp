// facebook easy
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
// 判断words中的顺序是否符合order的要求, 即hello 排在 leetcode 前面
// 给order分配顺序，然后遍历string
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> m;
        for (int i=0;i<order.length();i++) {
            m[order[i]]=i;
        }

        auto comp = [&](const string &a, const string &b) {
            int minl = min(a.length(),b.length());
            for (int i=0;i<minl;i++) {
                if (m[a[i]] < m[b[i]]) {
                    return true;
                } else if (m[a[i]] > m[b[i]]) {
                    return false;
                }
            }
            if (a.length()<=b.length()) {
                return true;
            } else {
                return false;
            }
        };

        for (int i=1;i<words.size();i++) {
            if (!comp(words[i-1],words[i])) return false;
        }
        return true;
    }
};