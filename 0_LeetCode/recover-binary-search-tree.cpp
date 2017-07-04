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
    void recoverTree(TreeNode* root) {
        bool flag = false;
        while (!flag) {flag = search(root, NULL, INT_MIN, INT_MAX);}
    }
private:
    bool search(TreeNode* root, TreeNode* prv, int left, int right) {
        if (root==NULL) return true;
        
        if (!(root->val<=right && root->val>=left)) {
            swap(root->val, prv->val);
            return false;
        }
        return search(root->left, root, left, root->val) && 
               search(root->right, root, root->val, right);
    }
};