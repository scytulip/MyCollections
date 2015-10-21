/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
class Solution {
public:
    void flatten(TreeNode *root) {
        stack<TreeNode*> stk_reod;   // Stack for tree reorder: pop 1, pop 2, 2->1
        stack<TreeNode*> stk_tree;      // Stack for recursive emulation
        stack<int> stk_vt;              // Visit indication: 0-no child visited, 1-left visited, 2-right visited
        int ind; 
        TreeNode *cur, *tmp;               // Current, temp node
        
        if (root==NULL) return;
        
        stk_tree.push(root);
        stk_vt.push(0);
        
        while(!stk_tree.empty())
        {
            ind = stk_vt.top(); stk_vt.pop();
            cur = stk_tree.top();
            
            if (!ind) stk_reod.push(cur); // Preorder: root first
            
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
            }
        }
        
        cur = stk_reod.top(); stk_reod.pop();
        cur->left = NULL; cur->right = NULL;    // Pop the last node
        
        while (!stk_reod.empty())
        {
            tmp = stk_reod.top(); stk_reod.pop();
            tmp->right = cur; tmp->left = NULL;     // Relink
            
            cur = tmp;
        }
        
        root = cur;
    }
};