/*
丑数=只有质数2,3,5作为因子   
当前面3个while都干完还不为1，说明不是丑数
*/
class Solution {
public:
    bool isUgly(int n) {
        while (true) {
            while (n%2==0) n=n/2;
            while (n%3==0) n=n/3;
            while (n%5==0) n=n/5;
            if (n==1) return true; else return false;
        }
    }
};