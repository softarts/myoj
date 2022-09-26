//2021

// 给一个父子关系的边，判断这里面的root最深的是哪个，如果一样深，给出id最小的
// union and find算法,但是这里没用
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int findRoot(unordered_map<int,int> &edges) {
      unordered_map<int,int> ans;
      for (auto &it:edges) {
          int child = it.first;
          int parent = it.second;
          //union find 算法，将每个edge最终指向其parent
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

int main() {
    Solution obj;
    unordered_map<int,int> edges{{1,2},{2,3},{3,4}};
    cout << (obj.findRoot(edges)== 4) << endl;
}
