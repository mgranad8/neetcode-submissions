/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public boolean hasCycle(ListNode head) {
        //check for an empty head
        if(head == null){
            return false; //no cycle on empty list
        }

        //intialize the pointers
        ListNode slow = head;
        ListNode fast = head;

        //start looping
        while(fast != null && fast.next != null){
            //start Floyd's cycle detection algorithm
            slow = slow.next;
            fast = fast.next.next;

            //check if the nodes match
            if(fast == slow){
                //if they match, return true
                return true;
            }
        }

        //otherwise, we break the loop and no cycle
        return false;
    }
}
