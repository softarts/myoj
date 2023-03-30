#include <vector>
using namespace std;

/*
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
[1,3,1] => 1
1,1,3
这道题目不是很容易理解，遍历，找出第一个c[i]<i的地方
*/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(), greater<int>());
        int n=citations.size();
        int ans=0;
        for (int i=1;i<=n;i++) {
            // 直到i=4, c[3]=1 时才break            
            // c[0]=6, i=1,不符合题意(6)，这里只有一篇
            if (citations[i-1] < i) break;  // 说明前面的i～3, c[i]>=i 都符合题意
            ans = i;
        }
        return ans;
    }
};