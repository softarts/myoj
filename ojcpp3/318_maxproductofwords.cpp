#include <vector>
#include <bitset>
#include <unordered_map>
using namespace std;

/*
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".

xtfn - abcdef ==>f 如何跳过
fntx  abcdef

这题没什么特别的，使用bitset， 然后O(N^2)
特点，使用vector来保存所有元素的bitset

*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<bitset<26>> vec(words.size());
        for (int i=0;i<words.size();i++) {
            for (auto c: words[i]) {
                vec[i][c-'a'] = 1;
            }
        }
        int ans=INT_MIN;
        for (int i=0;i<words.size();i++) {
            for (int j=0;j<words.size();j++) {
                if (i!=j) {
                    if ((vec[i] & vec[j]) == 0) {
                        ans = max(ans, int(words[i].length()*words[j].length()));
                    }
                }
            }
        }
        return ans==INT_MIN?0:ans;
    }
};