#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
2022-12-30
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
相同数量的并不要求字母顺序
考虑priority_queue? 需要一个struct
所以使用多个map来转换

*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, vector<char>> mc;
        unordered_map<char , int> m;
        unordered_set<int> ms;
        
        for (int i=0;i<s.length();i++) {
            m[s[i]]++;
        }
        
        for (auto &it:m) {            
            mc[it.second].push_back(it.first);
            ms.insert(it.second);
        }


        vector<int> sortcounts(ms.begin(),ms.end());
        sort(sortcounts.begin(),sortcounts.end(), std::greater());
        string ans;
        for (int i=0;i<sortcounts.size();i++) {
            int c = sortcounts[i];
            for (auto &el:mc[c]) {
                for (int i=0;i<c;i++) {
                    ans+=el;
                }     
            }
        }
        return ans;
    }
};