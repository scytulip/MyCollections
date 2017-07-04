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
    int maxPathSum(TreeNode* root) {
        max_path = INT_MIN;
        max_path = max(max_path, search(root));
        return max_path;
    }
private:
    int max_path;
    
    int search(TreeNode* root) {
        int left, right, subv = 0;
        
        if (root->left != nullptr) {
            left = search(root->left);
            max_path = max(max_path, left);
            subv += left;
        } else {
            left = 0;
        }
        if (root->right != nullptr) {
            right = search(root->right);
            max_path = max(max_path, right);
            subv += right;
        } else {
            right = 0;
        }
        subv += (root->val);
        max_path = max(max_path, subv);
        
        return max(root->val, root->val+max(right, left));
    }
};