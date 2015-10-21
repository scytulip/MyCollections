/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space? YES
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *cur, *next, *last; // Current, Next, Last pointers
        
        if (head==NULL) return false; // Special condition
        
        cur = head;
        last = NULL;
        
        while (cur != NULL)
        {
            
            next = cur->next;
            cur->next = last; // Reverse link direction of current node
                
            last = cur;
            cur = next; // Move to next node
            
            if (cur==head) return true;
                
            // After this modification, if there's a cycle in the linked list,
            // pointer will finally go back to the head.
        }
        
        return false;
    }
};