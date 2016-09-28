/*
270. Closest Binary Search Tree Value My Submissions QuestionEditorial Solution
Total Accepted: 13371 Total Submissions: 38261 Difficulty: Easy
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
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
    int closestValue(TreeNode* root, double target) {
        if (root==NULL) return 0;
        md = numeric_limits<double>::max();
        val = root->val;
        search(root, target);
        return val;
    }
private:
    double md;
    int val;
    void search(TreeNode* root, double target) {
        if (target-(double)(root->val)==0) {
            md = 0; val = root->val; return;
        } else {
            double diff = target-(double)(root->val);
            if (abs(diff)<md) { md = abs(diff); val = root->val; }
            if (diff>0 && root->right!=NULL) search(root->right, target);
            if (diff<0 && root->left!=NULL) search(root->left, target);
        }
    }
};