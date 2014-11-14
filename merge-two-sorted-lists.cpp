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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        ListNode *pHead, *pCur;
        ListNode *pHead1, *pHead2;
        
        pCur = new ListNode(0);
        pHead = pCur; // Important
        pHead1 = l1;
        pHead2 = l2;
        
        if (l1==NULL && l2==NULL)
            return NULL;
        else if (l2==NULL)
            return l1;
        else if (l1==NULL)
            return l2;
        
        while (pHead1 != NULL || pHead2 != NULL)
        {
            if (pHead2 == NULL)
            {
                pCur->next = pHead1;
                break;
            } else if (pHead1 == NULL)
            {
                pCur->next = pHead2;
                break;
            } else
            {
                if (pHead1->val < pHead2->val)
                {
                    pCur->next = pHead1;
                    pHead1 = pHead1->next;
                } else
                {
                    pCur->next = pHead2;
                    pHead2 = pHead2->next;
                }
                pCur = pCur->next;
                pCur->next = NULL;
            }
            
        }
        
        return pHead->next;
        
    }
};