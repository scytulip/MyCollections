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
private:
    int num_k;
    int count;
    int val;
    void search(TreeNode* root)
    {
        if (root==NULL || val!=-1) return;
        
        search(root->left);
        
        count ++;
        if (count == num_k) {val = root->val;return;}
        
        search(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        num_k = k;
        count = 0;
        val = -1;
        search(root);
        return val;
    }
};