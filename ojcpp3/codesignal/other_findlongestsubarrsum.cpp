#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/*
找出子数组之和为s
lc???

pattern?
1,2,3,7,5=> 2,3,7
presum=>

5,11,16,17 18 19..
5,6, 5, 1, 1, 1,
因为是正数，所以可以一直累加，不会有重复值

*/
vector<int> solution(int s, vector<int> arr) {
    unordered_map<int,int> m{{0,-1}};
    int sum=0;
    int maxLen=INT_MIN;
    int start=INT_MIN,end=INT_MIN;
    for (int i=0;i<arr.size();i++) {
        sum+=arr[i];
        int num = sum-s;
        if (m.count(num) && m[num]<=i) {
            if (i-m[num]>maxLen) {
                start = m[num]+1;
                end = i;
                maxLen = i-m[num]; 
                // cout << start << "," << end << "," << maxLen << endl;
            }
        }
        if (sum!=0) m[sum] = i; //考虑到可能 0会出现在开头位置，所以对0进行特殊处理
    }
    return start==INT_MIN?vector<int>{-1}:vector<int>{start+1,end+1};
}

