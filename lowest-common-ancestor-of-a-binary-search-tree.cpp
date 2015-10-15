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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (p == q) return p;
        
        if (root == p)
            return p;
        else if (root == q)
            return q;
        
        TreeNode* lt = lowestCommonAncestor(root->left, p, q);
        TreeNode* rt = lowestCommonAncestor(root->right, p, q);
        
        if (lt==NULL && rt==NULL)
            return NULL;
        else if(lt==NULL)
            return rt;
        else if(rt==NULL)
            return lt;
        else
            return root;
    }
};