//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
#include <vector>
#include <deque>
#include "codesignal.h"

using namespace std;

vector<int> solution(Tree<int> * t) {
    // bfs since we can't use recusive
    vector<int> ans;
    if (t==nullptr) return ans;
    deque<Tree<int>*> q{t};
    while (!q.empty()) {
        auto *node = q.front();
        q.pop_front();
        ans.push_back(node->value);
        if (node->left) q.push_back(node->left);
        if (node->right) q.push_back(node->right);
    }
    return ans;
}
