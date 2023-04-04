#include <iostream>
#include <unordered_map>

/*
jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
Output: true
// 5-3=2, 3-2=1, 5-1=4
// 3,5=>2,3,5,6,10=>0,1,2,3,5,6,7,10=>0,1,2,3,4
// 3,5 => 2,3,5,6,8,10=>

// jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
// Output: false
// 2,6 =>2,4,8,12
// 退出条件？

// 3,5 => 3+3,5+5,3+5
// 5-3=2, 3-2=1, 5-1=4
// 2+3,2+5,4+

这是一个数学题
然而可以用BFS来解决...精彩！
想象一个大的杯子，可以用jug1,jug2两个杯子往里面加水，减水(模拟5-3这种)，即4个方向
如果到达相同的水即为已经访问过，退出
条件，看所有方向都遍历后能否找到结果, 不能超过两个杯的总和(必须在一个或二个杯子里),不能小于0，
5:19pm
*/
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        deque<int> deq{0};
        int action[]={-jug1Capacity,jug1Capacity,-jug2Capacity,jug2Capacity};
        unordered_map<int,bool> visited;

        while (!deq.empty()) {
            auto vol = deq.front();
            deq.pop_front();
            if (vol==targetCapacity) return true;
            if (visited.count(vol) || vol<0 || vol>(jug2Capacity+jug1Capacity)) {
                continue;
            }
            visited[vol]=true;

            for (int i=0;i<4;i++) {
                deq.push_back(vol+action[i]);
            }
        }
        return false;
    }
};