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
    ListNode* removeElements(ListNode* head, int val) {
        
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        ListNode* hd = head->next;
        ListNode* fo = head;
        
        while (hd->next!=NULL)
        {
            if (hd->val == val)
            {
                fo->next = hd->next;
                hd = hd->next;
            } else
            {
                fo = hd;
                hd = hd->next;
            }
        }
        
        if (hd->val == val) fo->next = hd->next;
        
        return head;
    }
};