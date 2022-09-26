#include <iostream>
using namespace std;

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// 在台阶1的时候，有1种跳法，在台阶2的时候，有2种跳法, 台阶3的时候=台阶2+台阶1的跳法=3
class Solution {
public:
    int climbStairs(int n) {
        int f1=1;
        int f2=2;
        int ans=0;
        if (n==1) return f1;
        if (n==2) return f2; 
        for (int i=3;i<=n;i++) {
            ans=f1+f2;
            f1=f2;
            f2=ans;
        }
        return ans;
    }
};