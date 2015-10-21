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
    bool isValidBSTBound(TreeNode *root, int lb, int ub)
    {
        if (root==NULL) return true;
        if (root->val <= lb || root->val >= ub || lb>=ub) return false;
        
        return isValidBSTBound(root->right, root->val, ub) &
                isValidBSTBound(root->left, lb, root->val);
    }
public:
    bool isValidBST(TreeNode *root) {
        if (root==NULL) return true;
        
        return isValidBSTBound(root->right, root->val, numeric_limits<int>::max()) &
                isValidBSTBound(root->left, numeric_limits<int>::min(), root->val);
    }
};