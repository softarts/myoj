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

/*
假设O(1)space 
*/
#include "../common.h"
using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        auto getCount = [](ListNode*node) {
            int count = 0;
            while (node) {
                node=node->next;count++;
            }
            return count;
        };

        int n = getCount(head);
        int k2=n-k;

    }
};