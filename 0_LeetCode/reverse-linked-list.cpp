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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        if (head->next == NULL) return head;
        
        ListNode* first;
        ListNode* second;
        ListNode* tmp;
        
        first = head;
        second = first->next;
        
        while(second != NULL)
        {
            tmp = second -> next;
            second->next = first;
            if (first == head) first->next = NULL;
            first = second;
            second = tmp;
        }
        
        return first;
    }
};