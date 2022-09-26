//
// Created by Rui Zhou on 9/4/18.
//

/*
 * Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

For example:

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

Hint:

Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], what should your return? Is this case a valid tree?
According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


 */

#include <codech/codech_def.h>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector <pair<int, int>> &edges) {
        unordered_set<int> visited;
        multimap<int, int> graph;
        for (auto &el : edges) {
            graph.insert(make_pair(el.first, el.second));
        }

        deque<int> q{0};
        while (!q.empty()) {
            int node = q.front();
            q.pop_front();
            auto eqiter = graph.equal_range(node);
            for (auto it = eqiter.first;it!=eqiter.second; ++it) {
                if (visited.count(it->second)) {
                    return false;
                } else {
                    q.push_back(it->second);
                    visited.insert(it->second);
                }
            }
        }
        return true;
    }
};


DEFINE_CODE_TEST(261_graph_valid_tree)
{
    Solution obj;
    {
        vector <pair<int, int>> edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
        VERIFY_CASE(obj.validTree(5, edges), true);
    }
    {
        vector <pair<int, int>> edges{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
        VERIFY_CASE(obj.validTree(edges.size(), edges), false);
    }
}