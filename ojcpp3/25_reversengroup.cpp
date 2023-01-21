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
#include <iostream>
using namespace std;

class Solution {
public:

    // return , new tail,newhead, new cur
    // 如果不足k个节点,则返回所有的逆序
    // 题目要求不足k个节点的时候不需逆序 !!!!
    tuple<ListNode*,ListNode*,ListNode*> reverse(ListNode*node,int depth) {        
        if (depth==1) {             
            cout << node->val << " -> ";              
            return tuple(node, node, node->next);
        }

        // only non-null noode
        if (node->next) {
            auto [prev, newhead,newcur]  = reverse(node->next, depth-1);
            prev->next=node;
            node->next=nullptr;
            cout << node->val << " -> ";   
            return tuple(node, newhead,newcur);
        } else {
            cout << node->val << " -> ";   
            return tuple(node, node,node->next);
        }        
    }
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     ListNode dummy;
    //     ListNode *prev = &dummy;
    //     ListNode *cur = head;

    //     while (cur) {            
    //         auto [tail,newhead,newcur] = reverse(cur,k);
    //         cout << "[newhead => " << (newhead?to_string(newhead->val):"null") << " ]";               
    //         prev->next=newhead;
    //         cur = newcur;
    //         prev = tail;
    //         cout << "[cur => " << (cur?to_string(cur->val):"null") << " ]";               
    //     }
    //     return dummy.next;
    // }


     pair<ListNode*,ListNode*> myreverse(ListNode *prevtail, ListNode *head,int depth) {        
          ListNode* newtail=head, *prev=head;
          head=head->next;
          while (depth>1) {
            auto tmp = prev;
            prev=head;
            head=head->next;
            prev->next=tmp;
            depth--;
          }
          newtail->next = head; //head is new cur
          prevtail->next = prev;        
          return pair(head, newtail);
    }

     ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* next=head;
        int count=0;
        while (next) {
            next=next->next;count++;
        }

        if (k<=1 || k>count) return head;
        int loop = count/k;

        ListNode dummy;
        ListNode* prevtail = &dummy;
        for (int i=0;i<loop;i++) {
             auto [newhead,newtail] = myreverse(prevtail, head, k);
             head = newhead;
             prevtail=newtail;
        }
        return dummy.next;
    } 
};