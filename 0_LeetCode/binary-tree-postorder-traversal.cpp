/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode *root) {
        
        vector<int> rt_val;         // Return list
        stack<TreeNode*> stk_tree;   // Stack for recursive emulation
        stack<int> stk_vt;          // Visit indication: 0-no child visited, 1-left visited, 2-right visited
        int ind; 
        TreeNode *cur;               // Current node
        
        if (root==NULL) return rt_val;
        
        stk_tree.push(root);
        stk_vt.push(0);
        
        while(!stk_tree.empty())
        {
            ind = stk_vt.top(); stk_vt.pop();
            cur = stk_tree.top();
            
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
                    rt_val.push_back(cur->val);
            }
        }
        
        return rt_val;
    }
};