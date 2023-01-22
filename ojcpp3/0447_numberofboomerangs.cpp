#include <vector>
using namespace std;
/*
You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Return the number of boomerangs.

 

Example 1:

Input: points = [[0,0],[1,0],[2,0]]
Output: 2
Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
从给出的坐标中找出能够得到i,j,k ,i-j = i-k的个数
感觉这是个kmeans算法? x
暴力法 11:43PM -11:58PM 没什么意思
*/
#include <cmath>
#include <unordered_map>
#include <unordered_set>
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int, int> m;        
        int ans = 0;
        for (int i=0;i<points.size();i++) {
            for (int j=0;j<points.size();j++) {
                if (i==j) continue;
                auto p1 = points[i];
                auto p2 = points[j];
                auto distance = pow(abs(p1[0]-p2[0]),2) +  pow(abs(p1[1]-p2[1]),2);
                m[distance]++;                
            }
            for (auto &iter:m) {
                ans+=iter.second*(iter.second-1);
            }
            m.clear();
        }
        return ans;
    }
};
