/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "../common.h"
#include <utility>

using namespace std;
/*
7-2-4-3
  5-6-4
  => 7-8-0-7

套路：
1. 用stack 不太好
2. 可以用递归?  NO!
2 先逆序    
 */
class Solution {
public:
    ListNode* reverse(ListNode *l) {
        ListNode* prev = nullptr;
        while (l) {
            ListNode* next = l->next;
            l->next = prev;
            prev = l;
            l = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        int carry=0;
        ListNode *prev = nullptr;
        while (l1 || l2 || carry) {
            int s = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            ListNode * node = new ListNode(s%10);
            carry = s/10;
            node->next=prev;
            prev=node;
            l1 = l1?l1->next:nullptr;
            l2 = l2?l2->next:nullptr;
        }
        return prev;
    }
};