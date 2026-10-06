# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return False
        
        #intialize pointers
        slow = head
        fast = head

        #run the loop
        while fast != None and fast.next != None:
            #start Floyd's cycle detection algorithm
            slow = slow.next
            fast = fast.next.next

            #compare the two nodes
            if fast == slow:
                #if they match then return true
                return True
            
        
        #otherwise, when we reach here there is no cycle
        return False