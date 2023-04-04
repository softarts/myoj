#include <string>
#include <deque>
#include <sstream>
#include <iostream>
using namespace std;

/*
Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
第一个点是root, 然后剩下的是left,right
8:28->
*/
class Solution {
public:
    //  这个实现有问题，无法解决1,#,#,2,#,#的问题，即不知道前面的树结束了
    // bool isValidSerialization(string preorder) {
    //     deque<string> deq;
    //     std::istringstream ss(preorder);
    //     for (std::string line; std::getline(ss, line, ',');) {
    //         deq.push_back(line);
    //     }
    //     if (deq.size()==1 && deq[0]=="#") return true;
    //     while (!deq.empty()) {
    //         if (deq[0]=="#" || !validate(deq)) return false;
    //     }
    //     return true;
    // }

    // bool validate(deque<string> &arr) {
    //     if (arr.empty()) return false;
    //     if (arr[0]=="#") {
    //         arr.pop_front();return true;
    //     }
    //     arr.pop_front();
    //     bool left = validate(arr);
    //     bool right = validate(arr);
    //     return left && right;
    // }

    // 观察规律，凡是一个数字加两个#都可以是一个有效的子树，变为#，只要到最后得到一个#即可
    bool isValidSerialization(string preorder) {
        deque<string> deq;
        std::istringstream ss(preorder);
        for (std::string line; std::getline(ss, line, ',');) {
            deq.push_back(line);
            while (deq.size()>=3 && deq[deq.size()-1]=="#" && deq[deq.size()-2]=="#" && deq[deq.size()-3]!="#") {
                deq.pop_back();deq.pop_back();deq.pop_back();
                deq.push_back("#");
            }
        }
        return deq.size()==1 && deq[0]=="#";
    }
};

int main() {
    Solution obj;    
    cout << boolalpha << (obj.isValidSerialization("#")==true) << endl;
    cout << boolalpha << (obj.isValidSerialization("1,#,#,#,#")==false) << endl;    
    cout << boolalpha << (obj.isValidSerialization("1,#,#,2,#,#")==false) << endl;
    cout << boolalpha << (obj.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#")==true) << endl;   
}