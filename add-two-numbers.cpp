/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
private:
    int getsum(ListNode *l1, ListNode *l2, int carry)
    {
        int a = (l1==NULL)? 0 : l1->val;
        int b = (l2==NULL)? 0 : l2->val;
        return a+b+carry;
    }
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        ListNode *vn1, *vn2, *rt_val;   // Number1, Number2 & Return value
        ListNode *cur, *tmp;            // Current, Temp pointers
        int carry, sum;                 // Carry, Sum
        
        vn1 = l1;
        vn2 = l2;
        
        sum = getsum(vn1, vn2, 0);
        carry = sum / 10;
        rt_val = new ListNode(sum % 10);    // Head
        cur = rt_val;                       // Current = Head
        
        if (vn1!=NULL) vn1 = vn1->next;
        if (vn2!=NULL) vn2 = vn2->next;     // Move to next digit
        
        
        while (!(vn1==NULL && vn2==NULL))
        {
            sum = getsum(vn1, vn2, carry);
            carry = sum / 10;
            tmp = new ListNode(sum % 10);
            cur->next = tmp; cur = tmp;     // Add new node and move on
            
            if (vn1!=NULL) vn1 = vn1->next;
            if (vn2!=NULL) vn2 = vn2->next; // Move to next digit
        }
        
        if (carry)
        {
            tmp = new ListNode(1);
            cur->next = tmp;
        }
        
        return rt_val;
    }
};