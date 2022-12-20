#include <vector>
using namespace std;

// 垃圾题
bool solution(vector<int> a) {
    unordered_set<int> m(a.begin(),a.end());
    return m.size()!=a.size();
}


