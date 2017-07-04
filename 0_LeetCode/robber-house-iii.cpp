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
    int rob(TreeNode* root) {
        vector<int> ret = search(root);
        return max(ret[0], ret[1]);
    }
private:
    vector<int> search(TreeNode* root) { //0-steal, 1-no
        if (root==nullptr) return vector<int>(2,0);
        
        vector<int> result(2,0);
        vector<int> lt = search(root->left);
        vector<int> rt = search(root->right);
        
        result[0] = root->val + lt[1] + rt[1];
        result[1] = INT_MIN;
        result[1] = max(result[1], lt[0] + rt[0]);
        result[1] = max(result[1], lt[1] + rt[0]);
        result[1] = max(result[1], lt[0] + rt[1]);
        result[1] = max(result[1], lt[1] + rt[1]);
        
        return result;
    }
};