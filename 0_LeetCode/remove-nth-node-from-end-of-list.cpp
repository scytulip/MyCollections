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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail, *nth;
        int ct = 0;
        
        if (NULL == head) return NULL;
        
        /* Init */
        tail = head;
        nth = NULL;
        
        /* Go through */
        while (tail != NULL)
        {
            tail = tail -> next;
            if (ct == n)
            {
                nth = head;
            } else if (ct > n)
            {
                nth = nth -> next;
            }
            ct ++;
        }
        
        /* Judge */
        if (ct == n)
            return head->next;
        else if (nth == NULL)
            return head;
        else
        {
            nth->next = nth->next->next;
            return head;
        }
    }
};