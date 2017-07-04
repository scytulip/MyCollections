/*
250. Count Univalue Subtrees  QuestionEditorial Solution  My Submissions
Total Accepted: 7326
Total Submissions: 19412
Difficulty: Medium
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
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
    int countUnivalSubtrees(TreeNode* root) {
        if (root==NULL) return 0;
        
        count = 0;
        search(root);
        return count;
    }
private:
    int count;
    bool search(TreeNode* root) {
        if (root==NULL) return true;
        
        bool left = (root->left==NULL) ? true : search(root->left);
        bool right = (root->right==NULL) ? true : search(root->right);
        bool flag = left && right &&
                    (root->left==NULL || root->val==root->left->val) &&
                    (root->right==NULL || root->val==root->right->val);
        if (flag) ++count;
        
        return flag;
    }
};