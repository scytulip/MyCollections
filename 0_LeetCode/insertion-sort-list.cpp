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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *pt, *inst, *idx;
        ListNode *rt_val;
        
        if (head==NULL) return NULL;
        if (head->next==NULL) return head;
        
        pt = head;
        rt_val = head;
        
        while(pt->next!=NULL)
        {
            if (pt->val > pt->next->val)
            {
                inst = pt->next; // Value to be inserted
                pt->next = inst->next;
                
                idx = rt_val;
                if (inst->val<=idx->val) // becomes the new head
                {
                    inst->next = idx;
                    rt_val = inst;
                }
                else 
                {   // Head didn't change, insert in the middle
                    while(inst->val>idx->next->val) idx = idx->next;
                    inst->next = idx->next;
                    idx->next = inst;
                }
            }
            else
                pt = pt->next;
        }
        
        return rt_val;
    }
};