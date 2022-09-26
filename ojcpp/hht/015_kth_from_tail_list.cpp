//
// Created by rui.zhou on 5/6/2019.
//

#include <codech/codech_def.h>
using namespace std;
using namespace CODECH;
namespace {
    class Solution {
    public:
        ListNode* findKth(ListNode *head,int k) {
            ListNode *p1 = head;
            ListNode *p2 = head;
            if (k==0) return nullptr;
            while (p2 && k>0) {
                p2=p2->next;k--;
            }
            if (k>0) {
                return nullptr;
            }
            while (p2) {
                p2=p2->next;p1=p1->next;
            }
            return p1;
        }
    };
}

DEFINE_CODE_TEST(015_kth_tail_list)
{
    Solution obj;
    {
        ListNode *h=CREATE_LIST({1,2,3,4,5,6,7,8,9});
        VERIFY_CASE(obj.findKth(h,1)->val,9);
        VERIFY_CASE(obj.findKth(h,9)->val,1);
        VERIFY_CASE(obj.findKth(h,19),nullptr);
        VERIFY_CASE(obj.findKth(h,0),nullptr);
    }
}