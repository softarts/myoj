//
// Created by rui zhou on 15/04/18.
//

/*
 * https://leetcode.com/contest/weekly-contest-80/problems/linked-list-components/
 * We are given head, the head node of a linked list containing unique integer values.

We are also given the list G, a subset of the values in the linked list.

Return the number of connected components in G, where two values are connected if they appear consecutively in the linked list.

Example 1:

Input:
head: 0->1->2->3
G = [0, 1, 3]
Output: 2
Explanation:
0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:

Input:
head: 0->1->2->3->4
G = [0, 3, 1, 4]
Output: 2
Explanation:
0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
Note:

If N is the length of the linked list given by head, 1 <= N <= 10000.
The value of each node in the linked list will be in the range [0, N - 1].
1 <= G.length <= 10000.
G is a subset of all values in the linked list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
#include <codech/codech_def.h>
#include <codech/algo_common.h>

using namespace CODECH;
using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if (G.empty())
            return 0;
        if (G.size()==1)
            return 1;

        unordered_map<int, ListNode*> nodes;
        while (head) {
            nodes.insert(make_pair(head->val,head);
            head = head->next;
        }

        unordered_set<int> gs(G.begin(),G.end());



        auto iter = nodes.find(G[0]);
        if (iter == nodes.end()) {
            return 0;
        }

        ListNode *exp = iter->second->next;
        int num = 1;
        for (int i = 1; i< G.size(); i++) {
            if (exp==nullptr) {
                num++;
                auto iter = nodes.find(G[i]);
                exp = iter->second;
            } else if (G[i]!= exp->val) {
                num++;
                auto iter = nodes.find(G[i]);
                exp = iter->second;
            } else {
                exp = exp->next;
            }
        }
        return num;

    }
};

DEFINE_CODE_TEST(817_linkedlistcomponent)
{
    Solution obj;
    {
        ListNode *head = CREATE_LIST({0,1,2,3,4});
        vector<int> g{0,3,1,4};
        VERIFY_CASE(obj.numComponents(head,g),);
    }
}
*/