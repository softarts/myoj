//
// Created by rui.zhou on 3/12/2019.
//

/*
 * There are a number of spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. Start is always smaller than end. There will be at most 104 balloons.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6])
 and another arrow at x = 11 (bursting the other two balloons).
 注意，两个气球的边界相接处，可以同时射落2个气球
 */
#include <codech/codech_def.h>
using namespace std;

namespace lc452 {
    class Solution {
    public:
        int findMinArrowShots(vector<pair<int, int>>& points) {
            if (points.size()<2)
                return points.size();
            sort(points.begin(),points.end(),[](const pair<int,int> &a,const pair<int,int> &b){
                return a.second<b.second;
            });
            pair<int, int> &prev=points[0];
            int ans=1;
            for (int i=1;i<points.size();i++) {
                if (points[i].first>prev.second) {
                    ans++;
                    prev=points[i];
                }
            }
            return ans;
        }
    };
}

DEFINE_CODE_TEST(452_min_num_burst_ballon)
{
    lc452::Solution obj;
    {
        vector<pair<int,int>> points{{1,2},{2,3},{3,4},{4,5}};
        VERIFY_CASE(obj.findMinArrowShots(points),2);
    }
    {
        vector<pair<int,int>> points{{10,16}, {2,8}, {1,6}, {7,12}};
        VERIFY_CASE(obj.findMinArrowShots(points),2);
    }
    {
        vector<pair<int,int>> points{{7,12}};
        VERIFY_CASE(obj.findMinArrowShots(points),1);
    }
    {
        vector<pair<int,int>> points{};
        VERIFY_CASE(obj.findMinArrowShots(points),0);
    }

}