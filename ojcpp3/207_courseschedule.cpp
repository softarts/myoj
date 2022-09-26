#include <vector>
#include <unordered_map>
#include <forward_list>
#include <deque>
using namespace std;

/*
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

先整理出
每个course依赖的其他科目数量
每个course被依赖的科目列表
(0)->0
(1)->1
-----
(0)->1,2,3,4
这并不需要图来完成，
1.先找出所有0依赖的科目，放入ready queue
2. 在一个while循环里遍历ready queue,取出科目对应的被依赖列表，意味着都可以减少一项依赖
3. 如果依赖变为0，即可放入ready queue

*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, forward_list<int>> required;
        unordered_map<int,int> deps;
        for (int i=0;i<numCourses;i++) {
            deps[i] = 0;
            required[i]=forward_list<int>();
        }

        for (auto &el: prerequisites) {
            deps[el[0]] += 1;
            required[el[1]].push_front(el[0]);
        }

        deque<int> ready;
        for (int i=0;i<numCourses;i++) {
            if (deps[i] == 0) {
                ready.emplace_back(i);
            }
        }
        //vector<int> topo;
        int done = 0;
        while (!ready.empty()) {
            int course = ready.front();
            ready.pop_front();
            //topo.emplace_back(course);
            done++;
            for (auto &v:required[course]) {
                if (--deps[v] == 0) {
                    ready.emplace_back(v);
                }
            }
        }
        return done==numCourses;
    }
};