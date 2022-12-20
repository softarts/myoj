#include "codesignal.h"
#include <vector>
#include <deque>

using namespace std;
vector<int> solution(Tree<int> * t) {
    // also bfs
    vector<int> ans;
    if (t==nullptr) return ans;
    deque<Tree<int>*> q{t};
    while (!q.empty()) {
        int sz = q.size();
        int maxv = INT_MIN;
        for (int i=0;i<sz;i++) {
            auto *node = q.front();
            q.pop_front();
            maxv = max(maxv, node->value);            
            if (node->left) q.push_back(node->left);
            if (node->right) q.push_back(node->right);
        }
        ans.push_back(maxv);
    }
    return ans;
}
