//
// Created by rui.zhou on 5/9/2019.
//
#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;

// LC160
// 不知道是否有公共节点，先判断两个List最后一个节点是否相同
// 1. 长的链表先走几步,然后再同时走，相遇的节点为公共节点
// 2. L1,L2循环走，相遇的节点为公共节点，多出来的那段走的次数为相同部分的倍数就可以。
namespace {
    class Solution {
    public:
        ListNode *findFirstCommonNode(ListNode *h1,ListNode *h2) {
            ListNode *cur1=h1,*cur2=h2;
            while (cur1!=cur2) {
                cur1=cur1?cur1->next:h1;  // -> h2 better,switch,why? 1 loop can meet
                cur2=cur2?cur2->next:h2;  //h1
            }
            return cur1;
        }
    };
}