#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// Input: circles = [[2,2,1]]
// Output: 5
// Explanation:
// The figure above shows the given circle.
// The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
// Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
// Hence, the number of lattice points present inside at least one circle is 5.
// VF-4 原解法思路可能有点问题,需要找出新的思路
// 要求O(N)??? 好像没见到这个解法
// 就是利用三角形三条边的关系，暴力遍历O(N^2)
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        vector<vector<bool>> pp(201, vector<bool>(201, false));
        int ans=0;
        for (auto&item:circles){
            int x = item[0];
            int y = item[1];
            int r = item[2];
            for (int i=x-r;i<=x+r;i++) {
                int l = sqrt(r*r - (x - i)*(x - i));
                for(int j = y - l; j<= y+l; j++) {
                    if(!pp[i][j]) ans++;
                    pp[i][j] = true;
                }
            }
        }
        return ans;
    }
};