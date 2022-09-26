//
// Created by Rui Zhou on 16/3/18.
//

/*
 * https://leetcode.com/problems/palindrome-linked-list/description/
 * Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

 easy
 -> array is easy
 use a stack O(N) ->easy
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
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }

        ListNode* cur = head;
        bool ret = compare(cur, head, tail);
        return ret;
    }

    bool compare(ListNode *cur, ListNode*&realHead, ListNode* realTail) {
        if (cur==realTail) {
            return realHead->val==cur->val;
        }

        bool ret = compare(cur->next, realHead, realTail);

        if (!ret) {
            return false;
        } else {
            realHead = realHead->next;
            return realHead->val==cur->val;
        }
    }
};


DEFINE_CODE_TEST(234_palindrome_linkedlist)
{
    Solution obj;

    {
        ListNode *head = CREATE_LIST({1,2,3,2,1});
        VERIFY_CASE(obj.isPalindrome(head), true);
    }

}
