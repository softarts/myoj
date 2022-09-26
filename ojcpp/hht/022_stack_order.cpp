//
// Created by rui.zhou on 5/9/2019.
//
#include <codech/codech_def.h>
using namespace std;

// 两个整数序列，第一个是压栈顺序，判断第二个是否为出栈顺序
// {1,2,3,4,5} -> {4,5,3,2,1}, 即先pop 4后再push 5 {4,3,5,1,2}就不行
// 遍历pop 队列, 每一个数都在当前stack里找，有的话pop出来，没有就去push队列里，挨个push到stack里，有的话就表示找到，没找到就是false
namespace {

    class Solution {
    public:
        bool isPopOrder(const vector<int> &p,const vector<int>&o) {
            stack<int> st;
            if (p.empty()||o.empty()) return false;
            int pushIdx = 0;
            for (auto &ito:o) {
                if (!st.empty() && st.top()==ito) {
                    st.pop();
                }  else {
                    bool found=false;
                    for (;pushIdx<p.size();pushIdx++) {
                        if (p[pushIdx] == ito) {
                            found=true;pushIdx++;break;
                        } else {
                            st.push(p[pushIdx]);
                        }
                    }
                    if (!found) {
                        return false;
                    }
                }
            }

            return true;
        }
    };
}

DEFINE_CODE_TEST(hht_022_stack_order)
{
    Solution obj;
    {
        VERIFY_CASE(obj.isPopOrder({1, 2, 3, 4, 5}, {4, 5, 3, 2, 1}),true);
        VERIFY_CASE(obj.isPopOrder({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}),false);


    }
}