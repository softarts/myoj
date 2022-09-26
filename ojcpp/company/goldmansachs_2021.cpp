#include <codech/codech_def.h>
using namespace std;

/*
goldman sachs
root of largest tree in forest
https://leetcode.com/discuss/interview-question/674194/goldman-sachs-telephonic-round-2
变种
https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
给一个父子关系的边，判断这里面的root最深的是哪个，如果一样深，给出id最小的
*/

namespace {
    class Solution {
    public:
        int findRoot(unordered_map<int,int> &edges) {
            // unordered_map<int,int> m;
            // for (auto &it:edges) {
            //     m[it.first] = it.second;
            // }

            unordered_map<int,int> ans;
            for (auto &it:edges) {
                int child = it.first;
                int parent = it.second;
                while (edges.count(parent)) {
                    edges[child] = edges[parent];
                    parent = edges[parent];
                }
                ans[parent]++;
            }

            int maxCount = INT_MIN;
            int rootId;
            for (auto &it:ans) {
                if (it.second > maxCount) {
                    maxCount = it.second;
                    rootId = it.first;
                }
            }
            return rootId;
        }
    };

    // implement hashmap refer to cpp/hashmap
}

DEFINE_CODE_TEST(gs_2021)
{
    {
        Solution obj;
        unordered_map<int,int> edges{{1,2},{2,3},{3,4}};
        VERIFY_CASE(obj.findRoot(edges),4);
    }
}
