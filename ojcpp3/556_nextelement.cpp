//2022-10-05T13:53:10.000+08:00
// 类似lazada 的next element,但那个只提供了两个数
// Input: n = 12
// Output: 21
// 21 => -1
// 123 =>132, 321=> -1
// 132 => 213, 122=> 212
// 1 => -1, 2=> -1
// 230241=>230421
//241=>421  规律?

// 这是 next permutation的解法
// 1　　2　　7　　4　　3　　1 为例, => 131247
// 找出第一个降序的点=> 2, 降序意味着后面已经是最大值，无法进行任何交换。需要从降序的数字里找出一个最小的大于2的数字与降序点交换
// 与2交换后，再将后面逆序，即变为升序最小
// 如果已经是升序了, 例如1234,那么找出4之后,第一个大于3的数字，这里就是4，交换=> 1243
// 交换后再逆序，3后面已经没有数字了，所以不变
// for (int k = len - 2; k >= 0; k--) {
//     if (s[k] < s[k + 1]) { // 从后往前看, 第一个前面小于后面的数字， 2<7,[k]=>2， 后面是升序趋势
//         int i = k + 1;  // 此时意味着2后面全部是降序
//         while (i < len - 1 && s[i + 1] > s[k]) i++; // 从4开始往后看，找到最小的一个但是比2大的
//         swap(s[k], s[i]);
//         reverse(s.begin() + k + 1, s.end());
//         return (len == 10 && s > "2147483647") ? -1 : stoi(s);
//     }
// }

#include <string>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     int nextGreaterElement(int n) {
//         string s = to_string(n);
//         int len = s.size();
//         for (int k = len - 2; k >= 0; k--) {
//             if (s[k] < s[k + 1]) {
//                 int i = k + 1;
//                 while (i < len - 1 && s[i + 1] > s[k]) i++;
//                 //cout << "swap:"<<s[k] << ","<<s[i]<<endl;
//                 swap(s[k], s[i]);
//                 reverse(s.begin() + k + 1, s.end());
//                 return (len == 10 && s > "2147483647") ? -1 : stoi(s);
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int l=s.length();
        for (int i=l-1;i>0;i--) {
            // 找到升序点
            if (s[i]>s[i-1]) {
                // 从i往后找到一个最小的数，同时又大于s[i-1]
                int k=i;
                while (k<l && s[k]>s[i-1]) k++;
                // 交换这两个数，可能就是升序点的那个数
                swap(s[i-1],s[k-1]);
                // 再逆序，但是位置在升序点右
                reverse(s.begin()+i,s.end());
                long ans=stol(s);
                return ans>INT_MAX?-1:ans;
            }
        }
        return -1;
    }
};
int main() {
    Solution obj;
    cout << boolalpha << (obj.nextGreaterElement(127431)==131247) <<endl;

}