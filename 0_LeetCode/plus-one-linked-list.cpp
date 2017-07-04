/*
369. Plus One Linked List  QuestionEditorial Solution  My Submissions
Total Accepted: 1510
Total Submissions: 3086
Difficulty: Medium
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4

*/

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
    ListNode* plusOne(ListNode* head) {
        if (head==NULL) return NULL;
        
        head = reverseList(head);
        ListNode* node = head;
        int carry = 1;
        
        while (node!=NULL) {
            node->val += carry;
            carry = node->val / 10;
            node->val %= 10;
            if (node->next == NULL && carry != 0) node->next = new ListNode(0);
            node = node->next;
        }
        
        return reverseList(head);
    }
private:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* a = NULL;
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