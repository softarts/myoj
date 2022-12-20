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
#include <vector>
using namespace std;
/*
1-0-3
   -1
 -4
 =?103+101+14=218
 */


long sum=0;
void helper(Tree<int>*t, long cur) {
    if (t==nullptr) return;
    
    cur=cur*10+t->value;    
    if (!t->left && !t->right) {        
        sum+=cur;
        return;
    } 
    helper(t->left,cur);
    helper(t->right,cur);
}

long long solution(Tree<int> * t) {
    helper(t, 0);
}

