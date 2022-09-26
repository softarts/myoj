//
// Created by Rui Zhou on 14/3/18.
//

/*
 * https://leetcode.com/problems/delete-node-in-a-linked-list/description/
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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
    void deleteNode(ListNode* node) {
        // copy the rest node
        ListNode *next = node->next;
        while (next) {
            node->val = next->val;
            if (next->next == nullptr) {
                node->next = nullptr;
                break;
            } else {
                node = next;
                next = next->next;
            }

        }

    }

    void deleteNode1(ListNode* node) {
        ListNode * prev;
        ListNode *next = node->next;
        while (next) {
            node->val = next->val;
            prev = node;
            node = next;
            next = next->next;
        }
        prev->next = nullptr;
    }
};

DEFINE_CODE_TEST(237_delete_node_linkedlist)
{
    Solution obj;
    {
        ListNode *head = CREATE_LIST({1,2,3,4});
        ListNode *p3 = FIND_LISTNODE(head, 3);
        obj.deleteNode1(p3);
        VERIFY_CASE(PRINT_LIST(head),"1 2 4");
    }

}

