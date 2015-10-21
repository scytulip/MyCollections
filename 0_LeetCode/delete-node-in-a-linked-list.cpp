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
    void deleteNode(ListNode* node) {
        if (node == NULL) return;
        
        if (node->next == NULL)
        {
            node = NULL;
            return;
        }
        
        ListNode* nd = node;
        while(nd->next->next != NULL)
        {
            nd->val = nd->next->val;
            nd = nd->next;
        }
        nd->val = nd->next->val;
        nd->next = NULL;
    }
};