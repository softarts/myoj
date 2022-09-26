//
// Created by rui zhou on 23/03/18.
//

/*
 * https://leetcode.com/problems/odd-even-linked-list/description/
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
 */

#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pEven = nullptr, *pEvenHead = nullptr, *pOdd = nullptr, *pOddHead = nullptr;

        int idx = 1;

        while (cur) {
            if (idx % 2 == 0) {
                if (pEven) {
                    pEven->next = cur;
                } else {
                    pEvenHead = cur;
                }
                pEven = cur;
            } else {
                if (pOdd) {
                    pOdd->next = cur;
                } else {
                    pOddHead = cur;
                }
                pOdd = cur;
            }
            cur = cur->next;
            idx++;
        }

        if (pOdd)
            pOdd->next = pEvenHead;
        if (pEven)
            pEven->next = nullptr;
        return pOddHead;
    }
};


DEFINE_CODE_TEST(328_oldeven_linkedlist)
{
    Solution obj;
    {
        ListNode *head = CREATE_LIST({1,2,3,4,5});
        VERIFY_CASE(PRINT_LIST(obj.oddEvenList(head)),"1 3 5 2 4");
    }
    {
        ListNode *head = CREATE_LIST({1});
        VERIFY_CASE(PRINT_LIST(obj.oddEvenList(head)),"1");
    }
    {
        ListNode *head = CREATE_LIST({1,2});
        VERIFY_CASE(PRINT_LIST(obj.oddEvenList(head)),"1 2");
    }

    {
        ListNode *head = CREATE_LIST({1,2,3,4,5,6,7,8});
        VERIFY_CASE(PRINT_LIST(obj.oddEvenList(head)),"1 3 5 7 2 4 6 8");
    }
}