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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m>=n) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        dummy->next = head;
        for (int i=1; i<m; ++i) node = node->next;
        node->next = reverseList(node->next, n-m+1);
        return dummy->next;
    }
private:
    ListNode* reverseList(ListNode* head, int count) {
        if (head == NULL) return NULL;
        ListNode* a = NULL;
        ListNode* b = head;
        ListNode* c = NULL;
        for (int i=0; i<count; ++i) {
            c = b->next;
            b->next = a;
            a = b;
            b = c;
        }
        head->next = b;
        return a;
    }
};