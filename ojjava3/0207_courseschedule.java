/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

看是否能完成所有课程
1.传统方法使用图遍历有向图
2.使用topology sort

*/

import java.util.*;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> required = new HashMap<>();
        Map<Integer, Integer> depCounts = new HashMap<>();
        for (int i = 0; i < numCourses; i++) {
            depCounts.put(i, 0);
        }

        for (int[] p : prerequisites) {
            required.computeIfAbsent(p[1], k -> new ArrayList<>()).add(p[0]); // graph dependencies
            depCounts.put(p[0], depCounts.get(p[0]) + 1);
        }

        Deque<Integer> noDeps = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) {
            if (depCounts.get(i) == 0) {
                noDeps.add(i);
            }
        }

        // topology sort, reduce the nodeps one by one.
        List<Integer> topo = new ArrayList<>();
        while (!noDeps.isEmpty()) {
            int course = noDeps.poll();
            topo.add(course); // first take courses with no prerequisites

            if (required.containsKey(course)) {
                for (int next : required.get(course)) {
                    depCounts.put(next, depCounts.get(next) - 1);
                    if (depCounts.get(next) == 0) {
                        noDeps.add(next);
                    }
                }
            }
        }

        return topo.size() == numCourses;
    }

}