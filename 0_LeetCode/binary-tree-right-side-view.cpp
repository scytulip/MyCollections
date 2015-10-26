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
    vector<int> rec;
    void search(TreeNode* root, int lvl)
    {
        if (root==NULL) return;
        
        if (rec.size()<lvl) 
            rec.push_back(root->val);
        else
            rec[lvl-1] = root->val;
            
        search(root->left, lvl+1);
        search(root->right, lvl+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        search(root, 1);
        return rec;
    }
};