/*
Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
要求每次一个变种，而且变种必须在列表里
这道题其他地方出现过 类似lc127
9:11 
*/
#include <string>
#include <vector>
#include <unordered_set>
#include <deque>
#include <iostream>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> m(bank.begin(), bank.end());
        deque<string> deq{start};
        char choose[]={'A','C','G','T'};
        int steps=0;
        while (!deq.empty()) {
            int deqsz = deq.size();
            for (int k=0;k<deqsz;k++) {
                string s=deq.front();            
                deq.pop_front();
                if (s==end) {
                    return steps;
                }
                // string mutation=s;
                // add next
                for (int i=0;i<8;i++) {
                    char oriLetter = s[i];
                    for (int j=0;j<4;j++) {
                        if (choose[j]!=oriLetter) {
                            s[i] = choose[j];
                            if (m.count(s)) {
                                deq.push_back(s);
                                m.erase(s);
                            }
                        }
                    }
                    s[i] = oriLetter;
                }
            }
            steps++;
        }
        return -1;
    }
};

int main() {
    Solution obj;
    vector<string> bank{"AAAACCCC","AAACCCCC","AACCCCCC"};
    int actual = obj.minMutation("AAAAACCC","AACCCCCC",bank);
    cout <<boolalpha<< (actual==3) << endl;
}