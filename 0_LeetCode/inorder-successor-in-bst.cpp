/*
285. Inorder Successor in BST My Submissions QuestionEditorial Solution
Total Accepted: 9423 Total Submissions: 26324 Difficulty: Medium
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.
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
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root==NULL || p==NULL) return NULL;
        pf = false;
        marker = NULL;
        search(root, p);
        return marker;
    }
private:
    bool pf;
    TreeNode* marker;
    void search(TreeNode* root, TreeNode* p) {
        if (root->left!=NULL) search(root->left, p);
        if (marker!=NULL) return;
        
        if (pf) {
            marker = root;
            return;
        } else if (root==p) {
            pf = true;
        }
        
        if (root->right!=NULL) search(root->right, p);
        if (marker!=NULL) return;
    }
};