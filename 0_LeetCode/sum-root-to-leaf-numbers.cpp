/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
/* Based on tree postorder traversal */

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        
        int sum;                    // Return value
        int cur_val, last_val;      // Current & last value
        stack<TreeNode*> stk_tree;  // Stack for recursive emulation
        stack<int> stk_vt;          // Visit indication: 0-no child visited, 1-left visited, 2-right visited
        int ind; 
        TreeNode *cur;              // Current node
        
        if (root==NULL) return 0;
        
        stk_tree.push(root);
        stk_vt.push(0);
        cur_val = 0;
        sum = 0;
        
        while(!stk_tree.empty())
        {
            ind = stk_vt.top(); 
            stk_vt.pop();
            
            cur = stk_tree.top();
            
            if (!ind) 
            {
                cur_val = cur_val*10 + cur->val;
            }
            
            
            if (cur->left==NULL && cur->right==NULL) sum += cur_val; 
                // The end is reached, thus add current value to the sum.
            
            switch (ind)
            {
                case 0: // Left not visited
                    if (cur->left != NULL)
                    {
                        stk_tree.push(cur->left);
                        stk_vt.push(1);
                        stk_vt.push(0);
                        break;
                    }
                case 1: // Right not visited
                    if (cur->right != NULL)
                    {
                        stk_tree.push(cur->right);
                        stk_vt.push(2);
                        stk_vt.push(0);
                        break;
                    }
                case 2:
                    stk_tree.pop();
                    cur_val = (cur_val - cur->val) / 10;
            }
        }
        
        return sum;
        
    }
};