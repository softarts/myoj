#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;

// 类似78 那种subset的做法
class Solution {
public:
    vector<string> letterCombinations(string digits) {
         unordered_map<char, string> map{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},
                                            {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        //vector<string> ans;
        deque<string> ans;
        //init 
        for (auto &ch : map[digits[0]]) {
            ans.emplace_back(1,ch); // string(size,char)
        }

        for (int i=1;i<digits.length();i++) {
            string &choices = map[digits[i]];
            int n=ans.size();

            for (int j=0;j<n;j++) {
                string &el = ans.back();
                for (auto &ch : choices) {
                    ans.push_front(el+ch);
                }
                ans.pop_back();
            }
        }

        return vector<string>(ans.begin(),ans.end());
    }
};