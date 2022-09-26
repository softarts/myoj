//
// Created by Rui Zhou on 10/3/18.
//


/*
 * https://leetcode.com/problems/reverse-linked-list/description/
 * Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?

11:46 pm
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <codech/codech_def.h>
#include <codech/algo_common.h>


using namespace CODECH;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next=head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

DEFINE_CODE_TEST(206_reverselinkedlist)
{
    ListNode*head  = CREATE_LIST({1,2,3,4,5,6,7,8});
    Solution obj;
    PRINT_LIST(obj.reverseList(head));
}