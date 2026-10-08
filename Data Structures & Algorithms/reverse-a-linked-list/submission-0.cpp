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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }

        //intialize two pointers (previous and current)
        ListNode* prev = nullptr;
        ListNode* curr = head;

        //while curr is not null
        while(curr != nullptr){
            //create a next pointer
            ListNode* next = curr->next;

            //update the next values of the current node to equal the previous node
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        //once we reverse the list, the previous pointer is the new head
        return prev;
    }
};
