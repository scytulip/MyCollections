/*
Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Hint:

You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Param{
public:
    int min, max, n;
    Param() : min(INT_MAX), max(INT_MIN), n(0) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        max_bst = 0;
        search(root);
        return max_bst;
    }
private:
    int max_bst;
    
    Param search(TreeNode* root) {
        Param pm;
        if (root==NULL) return pm;
        
        Param left = search(root->left);
        Param right = search(root->right);
        
        if (left.max<=root->val &&
            right.min>=root->val) {
            pm.max = (root->right==NULL) ? root->val : right.max;
            pm.min = (root->left==NULL) ? root->val : left.min;
            pm.n = left.n + right.n + 1;
            if (pm.n>max_bst) max_bst = pm.n;
        } else {
            pm.max = INT_MAX;
            pm.min = INT_MIN;
            pm.n = 0;
        }
        return pm;
    }
};