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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *pt, *tmp;
        
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        
        pt = head;
        while (pt->next!=NULL)
        {
            if (pt->val==pt->next->val)
                pt->next = pt->next->next;
            else
                pt = pt->next;
        }
        
        return head;
        
    }
};