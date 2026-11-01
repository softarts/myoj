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
class Solution {
public:
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy=new ListNode();
        dummy.next = head;
        ListNode curr = head;
        Map<Integer, ListNode> map = new HashMap<>();
        map.put(0,dummy);

        int sum =0;
        while(curr!=null) {
            sum+=curr.val;
            if (map.containsKey(sum)) {
                // ListNode prev = m.get(sum);
                // prev.next = head.next;
                
                

                 // 如果前缀和重复了，说明中间这一段子链表和为 0
                ListNode prev = map.get(sum);
                ListNode toRemove = prev.next;
                int tempSum = sum;
                
                // 从哈希表中移除被删掉的那些中间节点对应的9前缀和
                while (toRemove != curr) {
                    tempSum += toRemove.val;
                    map.remove(tempSum);
                    toRemove = toRemove.next;
                }
                
                // 将前一个节点直接跳过中间和为 0 的部分，连到当前节点
                prev.next = curr.next;
            } else {
              map.put(sum,curr);
            }
            
            curr = curr.next;
        }
        return dummy.next;     
    }

};