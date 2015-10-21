/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode *head) {
        
        queue<ListNode *> que_node;
        stack<ListNode *> stk_node;
        ListNode *cur, *tmp;
        
        int i, len = 0;
        cur = head;
        
        while (cur != NULL)
        {
            stk_node.push(cur); // Stack
            que_node.push(cur); // Q
            cur = cur -> next;
            len ++;
        }
        
        cur = que_node.front(); // L0
        que_node.pop();
        
        for (i=1; i<len; i++)
        {
            if (i % 2)
            {
                tmp = stk_node.top(); // Ln, Ln-1, Ln-2, ...
                stk_node.pop();
                cur->next = tmp;
            } else
            {
                tmp = que_node.front(); // L1, L2, ...
                que_node.pop();
                cur->next = tmp;
            }
            cur = tmp;
        }
        
        if (cur != NULL) cur->next = NULL;
        
    }
};