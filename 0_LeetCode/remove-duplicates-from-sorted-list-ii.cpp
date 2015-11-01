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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head==NULL) return NULL;
        
        ListNode* hd = new ListNode(-head->val);
        hd->next = head;
        
        bool flag = false;
        ListNode* a = hd;
        ListNode* b = head;
        while (b->next != NULL)
        {
            if (b->val == b->next->val) 
            {
                b = b->next;
                flag = true;
            }
            else
            {
                if (flag) 
                {
                    a->next = b->next;
                    b = b->next;
                    flag = false;
                } else
                {
                    a = b;
                    b = b->next;
                }
            }
        }
        
        if (flag) a->next = NULL;
        
        a = hd->next;
        delete hd;
        return a;
    }
};