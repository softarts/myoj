#include <vector>
#include <map>
#include <iostream>
using namespace std;

/*
Input: intervals = [[3,4],[2,3],[1,2]]
Output: [-1,0,1]
Explanation: There is no right interval for [3,4].
The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.

给出的interval array, 找到其右侧interval
要排序, 然后还需要一个stack 来清空
或者使用map!!!!==>正解
以此为例
[[1,12],[2,9],[3,10],[13,14],[15,16],[16,17]]
建立一个treemap,key 为start,value为index=> m[1]=0,m[2]=1，使用map,因为强调了start point of interval是unique的
在具体搜索的时候，以endpoint的lower_bound查找（即equal or greater)
2022/10/22
*/
class Solution {
public:
    // vector<int> findRightInterval(vector<vector<int>>& intervals) {
    //     vector<int> ans(intervals.size(),-1);
                
    //     for (int i=0;i<intervals.size();i++) {
    //         intervals[i].push_back(i);
    //     }

    //     sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
    //         if (a[0]!=b[0]) {
    //             return a[0]<b[0];
    //         } else if (a[1]!=b[1]){
    //             return a[1]<b[1];
    //         } else {
    //             return true;
    //         }
    //     });
        
    //     // for (int i=0;i<intervals.size();i++) {
    //     //     cout << intervals[i][0] << ","<< intervals[i][1]<<endl;
    //     // }
    //     for (int i=1;i<intervals.size();i++) {
    //         if (intervals[i][0]>=intervals[i-1][1]) {
    //             ans[intervals[i-1][2]] = intervals[i][2];
    //         } else {
    //             ans[intervals[i-1][2]] = -1;
    //         }
    //     }
    //     //ans.push_back(-1);
    //     return ans;
    // }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans(intervals.size());
        map<int,int> m;
        for (int i=0;i<intervals.size();i++) {
            m[intervals[i][0]] = i;
        }

        for (int i=0;i<intervals.size();i++) {
            auto iter=m.lower_bound(intervals[i][1]);
            ans[i]=iter!=m.end()?iter->second:-1;
        }
        return ans;
    }
};