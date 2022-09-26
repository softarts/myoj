//[1,5]組成不同的數，如何判斷下一個是什麽1,11,15,51,55,111,115
// 判断逻辑
// 不是next_permutation
// 2020 面试
#include <iostream>
using namespace std;

class Solution {
public:
  int nextNum(int num, int small, int big) {
      int right = 0,factor=1;
      while (num>0) {
          // 从最小位检查起
          int m = num%10;
          if (m == big) { // 如果是大的数字，则需要进位
              right = 1*factor + right;
          } else if (m==small) { // 小的数字只需要替换成大的数字即可
              return ((num/10)*10+big)*factor +right;
          } 
          factor*=10; //每检查一次,factor*10
          num=num/10;
      }
      return 1*factor + right;
  }
};

int main() {
    bool ret = true;
    Solution slu;
    cout << (slu.nextNum(1,1,5) == 5) << endl;
    cout << (slu.nextNum(5,1,5) == 11) << endl;
    cout << (slu.nextNum(15,1,5) == 51) << endl;
    cout << (slu.nextNum(111,1,5) == 115) << endl;
    cout << (slu.nextNum(555,1,5) == 1111) << endl;
    return 0;
}