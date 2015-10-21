/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
private:
    int countLev(TreeNode *root, bool &bal) //Count level of node
    {
        int a,b;
        
        if (root==NULL) return 0;
        
        a = countLev(root->left, bal);
        b = countLev(root->right, bal);
        
        if (abs(a-b)>=2) bal = false;
        
        return (a>b) ? a+1 : b+1;
    }
public:
    bool isBalanced(TreeNode *root) {
        
        if (root==NULL) return true;
        
        bool bal = true; // Return value
        
        countLev(root, bal);
        
        return bal;
    
    }
};