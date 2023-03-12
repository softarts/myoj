#include <iostream>
#include "../common.h"
using namespace std;
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




class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy;
        dummy.next = head;
        ListNode *cur=head;
        ListNode *prev = &dummy;
        while (cur) {
            if (cur->val==val) {
                prev->next = cur->next;                
            } else {
                prev->next = cur;
                prev = cur;
            }
            cur=cur->next;
        }

        return dummy.next;
    }
};