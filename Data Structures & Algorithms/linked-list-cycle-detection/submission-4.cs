/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */

public class Solution {
    public bool HasCycle(ListNode head) {
        //check if head is empty
        if(head == null){
            return false; //no cycle on empty list
        }

        //intialize pointers
        ListNode slow = head;
        ListNode fast = head;

        //loop through the linked list
        while(fast != null && fast.next != null){
            //start floyd's cycle algorithm
            slow = slow.next;
            fast = fast.next.next;

            //check to see if the nodes match
            if(fast == slow){
                return true; //nodes match
            }
        }

        //otherwise, no cycle and loop breaks
        return false;
    }
}
