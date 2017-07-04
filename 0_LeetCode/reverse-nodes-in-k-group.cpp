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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL) return NULL;
        if (k==1) return head;
        
        ListNode* node = head;
        for (int i=0; i<k-1; ++i) {
            if (node->next != NULL)
                node = node->next;
            else
                return head;
        }
        
        ListNode* next_group = node->next;
        node->next = NULL;
        
        return reverseList(head, reverseKGroup(next_group, k));
    }
private:
    ListNode* reverseList(ListNode* head, ListNode* end) {
        if (head == NULL) return NULL;
        ListNode* a = end;
        ListNode* b = head;
        ListNode* c = NULL;
        while (b!=NULL) {
            c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        return a;
    }
};