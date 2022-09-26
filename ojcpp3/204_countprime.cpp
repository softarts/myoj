/*
返回<n 的所有素数
*/


#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    //这是筛选法
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<int> flag(n,1);    //将标识初始化为true

        flag[0]=0;            //0不是素数
        flag[1]=0;            //1不是素数
        for(int i=2;i<n;++i) {
            // 当i为素数时，i的所有倍数都不是素数
            if(flag[i]) {
                for(int j=2*i;j<n;j+=i)     {
                    flag[j]=0;
                }
            }
            if (i*i>=n)
                break;
        }
        // 返回prime的个数而已
        int count = count_if(flag.begin(), flag.end(),[](int r){return r==1;});
        return count;
    }

    // 另外判断是否素数的的函数，从2到sqrt，判断是否有整除
    bool isPrime(int n) {
        for (int i=2;i<=sqrt(n);i++) {
            if (n%i==0) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution obj;
    cout << boolalpha << obj.isPrime(5) << endl;
    cout << boolalpha << obj.isPrime(9) << endl;
    cout << boolalpha << obj.isPrime(11) << endl;
}