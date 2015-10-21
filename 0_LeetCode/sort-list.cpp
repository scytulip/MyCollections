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
    ListNode *sortList(ListNode *head) {
        ListNode *tmp, *p1, *p2;
        bool in_p1;
        
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        
        if (head->next->next==NULL)
        {
            if (head->val > head->next->val)
            {
                tmp = head;
                head = head->next;
                head->next = tmp;
                tmp->next = NULL;
            }
            return head;
        }
        
        /* Divide */
        p1 = head;
        p2 = head;
        while(p2->next!=NULL)
        {
            p2 = p2->next;
            if (p2->next!=NULL)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        p2 = p1->next; p1->next = NULL;
        p1 = head;
        p1 = sortList(p1);
        p2 = sortList(p2); 
        
        /* Combine */
        if (p1->val <= p2->val)
        {
            head = p1; in_p1 = true;
        } else
        {
            head = p2; in_p1 = false;
        }
        
        while (p1!=NULL && p2!=NULL)
        {
            if (in_p1)
            {
                while(p1->next!=NULL && p1->next->val<=p2->val) p1 = p1->next;
                tmp = p1->next;
                p1->next = p2;
                p1 = tmp;
            }
            else
            {
                while(p2->next!=NULL && p2->next->val<=p1->val) p2 = p2->next;
                tmp = p2->next;
                p2->next = p1;
                p2 = tmp;
            }
            in_p1 = !in_p1;
        }
        
        return head;
    }
};