#include "../common.h"
#include <cstdlib>

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
/*
思路linkedlist的随机？转化为vector?
否则做不到O(1)
使用reservior sampling
https://blog.csdn.net/fuxuemingzhu/article/details/79488113
即在一个流中，每个元素都有相同的概率进入蓄水池
*/
class Solution {
public:
    ListNode* head_;
    Solution(ListNode* head) {
        this->head_ = head;
    }
    
    int getRandom() {
        int cnt=1;
        int ans;
        ListNode *p = head_;
        while (p) {
            if (rand()%cnt == 0) {
                ans = p->val;
            }
            p=p->next;cnt++;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */