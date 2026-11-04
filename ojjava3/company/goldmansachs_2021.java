package company;

/*
Q2. Largest Tree Root

Given a forest represented by parent-child relationships, return the root id of the tree containing the maximum number of nodes.

The input is given as a hashmap/dictionary where:

    key   = child id
    value = parent id

Assumptions:

1. Each child has exactly one parent.
2. A parent may have multiple children.
3. The input forms a valid forest (one or more disjoint trees).
4. If multiple trees have the same number of nodes, return the smaller root id.

Example:

Input:

[
    [2,3],
    [5,7],
    [3,4],
    [6,8],
    [1,4]
]

The forest is:

    2 -> 3 -> 4
              ^
              |
              1

    5 -> 7

    6 -> 8

Trees:

Root = 4, Nodes = {1,2,3,4} => Size = 4
Root = 7, Nodes = {5,7}     => Size = 2
Root = 8, Nodes = {6,8}     => Size = 2

Output:

4

Explanation:

The tree rooted at 4 contains the maximum number of nodes (4 nodes).

最开始的思路是并查集, 对于每一个node都要递归查找其parent
使用cache可以提高性能
 */

import java.util.*;

public class goldmansachs_2021 {
    public int findRoot(Map<Integer, Integer> edges) {
        int answer = -1;
        Map<Integer, Integer> count = new HashMap<>();
        
        int maxChilds = 0;
        for (Map.Entry<Integer, Integer> entry : edges.entrySet()) {
            int parent = entry.getValue();
            int root = find(parent, edges);
        
            int cur = count.getOrDefault(root, 0) + 1;
            count.put(root, cur);

            if (cur > maxChilds) {
                maxChilds = cur;
                answer = root;
            } else if (cur == maxChilds) {
                if (answer == -1 || root < answer) {
                    answer = root;
                }
            }
        }
        return answer;
    }


    private int find(int parent, Map<Integer, Integer> edges) {
        while (edges.containsKey(parent)) {
            parent = edges.get(parent);
        }
        return parent;
    }
}
