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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (0==k) return NULL;
        
        int i;
        while (k>1) {
            for (i=0; i<k/2; ++i) {
                lists[i] = merge2(lists[i*2], lists[i*2+1]);
            }
            if (k%2) lists[i] = lists[k-1];
            k = (k+1)/2;
        }
        return lists[0];
    }
    
private:
    ListNode* merge2(ListNode* a, ListNode* b) {
        ListNode* head;
        ListNode* cur;
        
        if (a!=NULL && (b==NULL || a->val<=b->val)) {
            head = a;
            a = a->next;
        } else if (b!=NULL) {
            head = b;
            b = b->next;
        } else {
            return NULL;
        }
        cur = head;
        
        while (a!=NULL || b!=NULL) {
            if (b==NULL || (a!=NULL && a->val<=b->val)) {
                cur->next = a;
                cur = cur->next;
                a = a->next;
            } else if (a==NULL || (b!=NULL && b->val<=a->val)) {
                cur->next = b;
                cur = cur->next;
                b = b->next;
            }
        }
        cur->next = NULL;
        
        return head;
    }
};