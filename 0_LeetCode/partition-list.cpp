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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* pHead = new ListNode(0);
        pHead->next = head;
        
        ListNode* x0 = pHead;
        ListNode* x1 = head; // First node >= x;
        while (x1 != NULL && x1->val<x)
        {
            x0=x1;
            x1=x1->next;
        }
        if (x1==NULL) return head;
        
        ListNode* x2 = x1;
        ListNode* x3 = x1->next;
        
        while (x3 != NULL)
        {
            if (x3->val>=x)
            {
                x2 = x3;
                x3 = x3->next;
            } else
            {
                x2->next = x3->next;
                x3->next = x1;
                x0->next = x3;
                x0 = x3;
                x3 = x2->next;
                
            }
        }
        
        return pHead->next;
    }
};