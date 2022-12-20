#include <deque>
#include <string>
using namespace std;

string solution0(int level, int pos) {
    deque<char> q{'E'};
    int i=1;
    while (i<=level) {
        int sz = q.size();
        for (int j=0;j<sz;j++) {
            auto c=q.front();
            q.pop_front();
            if (c=='E') {
                q.push_back('E');
                q.push_back('D');
            } else {
                q.push_back('D');
                q.push_back('E');
            }
        }
        i++;
    }
    char c;
    while (pos>0) {
        c=q.front();
        q.pop_front();
        pos--;
    }
    return c=='E'?"Engineer":"Doctor";
}

// 看bit里面1的个数，偶数个1 即为 doctor，奇数个1位engineer
// 这个太trick
string solution(int level, int pos) {
    if (level==1) return "Engineer";
    if (solution(level-1, (pos+1)/2) == "Doctor") {
        if (pos % 2== 0) {
            return "Engineer";
        } else {
            return "Doctor";
        }
    } else {
        // parent is Engineer
        if (pos % 2== 0) {
            return "Doctor";
        } else {
            return "Engineer";
        }
    }
}