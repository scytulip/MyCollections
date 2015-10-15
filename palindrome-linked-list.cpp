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
    bool isPalindrome(ListNode* head) {
        ListNode* tmp = head;
        
        // Round One: Count
        int count = 0;
        
        while(tmp!=NULL)
        {
            tmp = tmp->next;
            count ++;
        }
        
        if (count <= 1) return true;
        if (count == 2) return (head->val == head->next->val);
        if (count == 3) return (head->val == head->next->next->val);
        
        // Round Two: Reverse 1st half
        int i;
        ListNode* first = head;
        ListNode* second = head->next;
        
        for (i=0; i<count/2-1; i++)
        {
            tmp = second -> next;
            second->next = first;
            if (first == head) first->next = NULL;
            first = second;
            second = tmp;
        }
        
        if (count%2 == 1) second = second->next;
        
        // Round Three: Compare
        while (first != NULL)
        {
            if (first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};