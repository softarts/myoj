#include <iostream>
#include <unordered_set>
using namespace std;

/*
纯bt能否?
*/
class Solution {
public:
    int a[14];
    int len=0;
    int ans=0;
    int countNumbersWithUniqueDigits(int n) {
        n=pow(10,n);
        cout << n << endl;
        while (n>0) {
            a[++len] = n%10;
            n/=10;
        }
        unordered_set<int> m;
        helper(len,1,m);
        return ans;
    }

    void helper(int pos, int limit, unordered_set<int> &m) {
        if (!pos) {
            ans++;
            for (auto &it:m) {
                cout << it<< " ";
            }
            cout << endl;
            return;
        }

        int ub=limit?a[pos]:9;
        
        for (int i=0;i<=ub;i++) {
            if (!m.count(i)) {
                m.insert(i);
                helper(pos-1,limit&&i==a[pos],m);
                m.erase(i);
            }
        }
    }
};