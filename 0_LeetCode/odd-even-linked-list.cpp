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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        
        ListNode* even_head = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* nodd;
        ListNode* neven;
        while(odd->next!=NULL && odd->next->next!=NULL) {
            nodd = odd->next->next;
            neven = nodd->next;
            odd->next = nodd;
            even->next = neven;
            odd = nodd;
            even = neven;
        }
        
        odd->next = even_head;
        return head;
    }
};