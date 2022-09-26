//
// Created by rui zhou on 15/03/19.
//

/*
 * There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

 */
#include <codech/codech_def.h>
#include <forward_list>
using namespace std;
using namespace CODECH;

namespace lc210 {
    // a simpler impl?
    class Solution1 {
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
            unordered_map<int,forward_list<int>> requires;
            unordered_map<int,int> deps;
            for (int i=0;i<numCourses;i++) {
                deps[i] = 0;
                requires[i]=forward_list<int>();
            }

            for (auto &el: prerequisites) {
                deps[el.first] += 1;
                requires[el.second].push_front(el.first);
            }
            queue<int> ready;
            for (int i=0;i<numCourses;i++) {
                if (deps[i] == 0) {
                    ready.emplace(i);
                }
            }
            vector<int> topo;
            while (!ready.empty()) {
                int course = ready.front();
                ready.pop();
                topo.emplace_back(course);
                for (auto &v:requires[course]) {
                    if (--deps[v] == 0) {
                        ready.emplace(v);
                    }
                }
            }
            return topo.size()==numCourses?topo:vector<int>();
        }
    };

    //
    class Solution {
    private:
        unordered_set<int> finished;
        vector<int> ret;
    public:
        vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
            unordered_map<int,forward_list<int>> map;
            unordered_map<int,bool> visited;
            finished.clear();
            ret.clear();
            for (int i=0;i<numCourses;i++) {
                map[i] = forward_list<int>();
            }

            for (auto &el: prerequisites) {
                auto &lst = map[el.first];
                lst.push_front(el.second);
            }

            for (auto &iter:map) {
                stack<int> stk;
                if (!canFinish(iter.first,visited,map,stk))
                    return vector<int>();
            }
            return ret;
        }

        bool canFinish(int course,unordered_map<int,bool> &visited,
                unordered_map<int,forward_list<int>> &map,stack<int> &stk) {
            if (visited[course])
                return false;
            stk.push(course);
            visited[course] = true;
            for (auto &el:map[course]) {
                if (!canFinish(el,visited,map,stk))
                    return false;
            }

            if (!finished.count(course)) {
                finished.emplace(course);
                ret.push_back(course);
            }
            stk.pop();
            visited[course] = false;
            return true;
        }
    };
}

DEFINE_CODE_TEST(210_courseschedule2)
{
    lc210::Solution1 obj;
    {
        vector<pair<int, int>> pre{{1,0},{2,0},{3,1},{3,2}};
        //vector<vector<int>> exp{{0,1,2,3},{0,2,1,3}};
        VERIFY_CASE(PRINT_VEC(obj.findOrder(4,pre)),"0 2 1 3");
    }
    {
        vector<pair<int, int>> pre{};
        VERIFY_CASE(PRINT_VEC(obj.findOrder(1,pre)),"0");
    }
}