#include <iostream>
#include <vector>
using namespace std;

/*
Example 1:

Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199

backtracking?
设置一个longmax 避免判断过大的数字
退出条件就是comb中有多于3个数，但是不匹配,返回false
如果已到尽头并且comb匹配，返回true
数字已到尽头，不进入循环，最终返回false
*/
class Solution {
public:
    string long_max;
    bool isAdditiveNumber(string num) {
        vector<long> comb;
        long_max = to_string(LLONG_MAX);
        cout<<long_max<<endl;
        return helper(num, 0, comb);
    }

    bool helper(string &num,int start,vector<long> &comb) {
        // 剪枝
        if (comb.size()>=3) {
            int n=comb.size();
            if (comb[n-1]!=comb[n-2]+comb[n-3]) return false;
        }
        if (start== num.size() && comb.size()>=3) return true;


        
        for (int i=start;i<num.size();i++) {
            auto v = num.substr(start, i-start+1);
            
            
            if (v[0]=='0' && v.length()!=1) continue;//skip 0 leading
            if (v.size() > long_max.size() || v.size() == long_max.size() && v.compare(long_max) > 0)break;
            long curr = stoll(v);
            comb.push_back(curr);
            if (helper(num,i+1,comb)) return true;
            comb.pop_back();
        }
        return false;
    }
};