#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

套路就是先用hashmap记下所有char的lastindex，然后在第二次遍历的时候找出当前所能到达
的最远index，如果和当前index相同，则输出。
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for (int i=0;i<s.length();i++) {
            m[s[i]]=i;    
        }
        int maxv=0;
        int start=0;
        vector<int> ans;
        for (int i=0;i<s.length();i++) {
            maxv=max(maxv,m[s[i]]);
            if (i==maxv) {
                ans.push_back(i-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};