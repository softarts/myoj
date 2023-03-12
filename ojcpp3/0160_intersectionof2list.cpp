#include "common.h"
using namespace std;

// credit sussie
// 找出两个链表是否有公共节点, 不能使用set,
//  1 -2 -3 -4 -5 -6 -7 -|
//        | <- 9 <- 8 <- |
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur1=headA,*cur2=headB;
        int steps=0;
        while (cur1!=cur2) {
            if (++steps == 50000) return nullptr;
            // 这里好像交不交换并不重要，交换的话能尽快找到..也许只是错觉
            // 交换之后，正好弥补指针之间的差距
            cur1=cur1?cur1->next:headA;
            cur2=cur2?cur2->next:headB;
        }
        return cur1;
    }
};