/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

import ListNode from './ListNode'
function removeElements(head: ListNode | null, val: number): ListNode | null {
    let dummy = new ListNode()
    dummy.next = head
    let cur = head
    let prev= dummy
    while (cur) {
        if (cur.val === val) {
            prev.next = cur.next            
        } else {
            prev = cur
        }
        cur = cur.next
    }
    return dummy.next
};

// test here
let node = new ListNode()
let result = removeElements(node,1)
console.log(result)