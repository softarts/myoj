
//
// Binary trees are already defined with this interface:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

#include "codesignal.h"
using namespace std;

// lc572
bool helper(Tree<int> * t1, Tree<int> * t2) {
    if (t1 && t2) {
        return t1->value==t2->value && helper(t1->left, t2->left) && helper(t1->right, t2->right);
    } else {
        return t1==t2;
    }
}
bool solution(Tree<int> * t1, Tree<int> * t2) {
    return helper(t1,t2) || (t1&&solution(t1->left,t2)) || (t1&&solution(t1->right, t2));
}

