#include "../common.h"
using namespace std;

/*
O(n) & O(1) space
1-2-2-1
使用O(1)空间的话只能用递归，或者从中间断开
使用递归,cur=当前需要比较的node
*/
class Solution {
public:
    ListNode *cur;
    bool hitMiddle = false;
    bool isPalindrome(ListNode* head) {
        cur = head;
        return helper(head);
    }

    bool helper(ListNode *node) {
        if (node==nullptr) return true; // 到尾部了返回true
        if (helper(node->next)) {  //先递归再比较
            if (hitMiddle) return true; // 如果已到达middle则后面不用再比较
            if (node->val == cur->val) {
                if (cur->next==node) hitMiddle = true;                
                cur = cur->next;
                return true;
            }
        } 
        return false;
    }
};

/*
这个18年的解题，和上面类似，不过上面只需要1个固定cur,然后tail逐渐出栈
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

*/