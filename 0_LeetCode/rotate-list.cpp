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
    ListNode *rotateRight(ListNode *head, int k) {
        int i,j;
        ListNode *newhead, *pt;
        
        pt = head;
        
        if (pt==NULL) return NULL;
        i = 1;
        
        while (pt->next != NULL)
        {
            pt = pt->next;
            i++;
        }
        
        pt->next = head; // Link back
        
        for (j=0; j<(i-(k%i)); j++) // deal with k>i
        {
            pt = pt->next;
        }
        
        newhead = pt->next;
        pt->next = NULL;
        
        return newhead;
    }
};