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
    ListNode* swapPairs(ListNode* head) {
        ListNode* a;
        ListNode* b;
        ListNode* tmp;
        ListNode* pre;
        
        if (head == NULL) return NULL;
        
        pre = NULL;
        a = head;
        if (a!=NULL) b = head->next;
        while (a!=NULL && b!=NULL)
        {
            tmp = b->next;
            b->next = a;
            a->next = tmp;
            if (pre!=NULL) pre->next = b;
            pre = a;
            
            if (a==head) head = b;
            a = tmp;
            if (a!=NULL) b = tmp->next;
        }
        
        return head;
    }
};