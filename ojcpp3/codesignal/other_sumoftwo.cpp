#include <vector>
#include <unordered_set>
using namespace std;
/*
和twosum有点不一样
从两个arr中找是否有得到sum=target的，做法还是类似
*/
bool solution(vector<int> a, vector<int> b, int v) {
    unordered_set<int> sb(b.begin(),b.end());
    for (auto el: a) {
        if (sb.count(v-el)) {
            return true;
        }
    }
    return false;
}
