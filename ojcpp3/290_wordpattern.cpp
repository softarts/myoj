#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
用一个map不够，要两个双向的
*/
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        auto split = [](string &s) {
            vector<string> tokens;
            size_t pos = 0, start = 0;
            while ((pos = s.find(" ", start)) != string::npos) {
                string token = s.substr(start, pos-start);
                start = pos+1;                   
                tokens.push_back(token);
            }
            tokens.push_back(s.substr(start));
            return tokens;
        };

        auto tokens = split(s);
        if (tokens.size()!=pattern.length()) return false;
        unordered_map<char, string> m1;
        unordered_map<string, char> m2;        
        for (int i=0;i<pattern.length();i++) {
            char c = pattern[i];
            if (m1.count(c) || m2.count(tokens[i])) {
                if (m1[c]!=tokens[i]) return false;
                if (m2[tokens[i]]!=c) return false;
            } else {
                m1[c] = tokens[i];
                m2[tokens[i]] = c;
            }
        }
        return true;
    }
};