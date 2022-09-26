
#include "common.h"
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head==nullptr) return false;
        ListNode *fast=head,*slow=head;
        while (fast && slow) {
            fast=fast->next?fast->next->next:nullptr;
            slow=slow->next;
            if (fast==slow && fast!=nullptr) {
              return true;
            }
        }
        return false;
    }
};
