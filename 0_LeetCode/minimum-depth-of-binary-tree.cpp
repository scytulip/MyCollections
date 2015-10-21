/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root) {
        
        int a,b;
        
        if (root==NULL) return 0;
        
        if (root->right == NULL && root->left == NULL) return 1;
        
        if (root->left == NULL) 
            return minDepth(root->right) + 1;
        else if (root->right == NULL)
            return minDepth(root->left) + 1;
        else
        {
            a = minDepth(root->left) + 1;
            b = minDepth(root->right) + 1;
            return (a<b) ? a : b;
        }
    }
};