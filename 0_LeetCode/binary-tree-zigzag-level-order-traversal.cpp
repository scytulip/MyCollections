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
    vector<vector<int>> list;
    void zigzag(TreeNode* root, int lvl)
    {
        if (root==NULL) return;
        
        if (lvl >= list.size()) 
            list.push_back(vector<int>());
        
        if (lvl%2==0)    
            list[lvl].push_back(root->val);
        else
            list[lvl].insert(list[lvl].begin(), root->val);
        
        zigzag(root->left, lvl+1);
        zigzag(root->right, lvl+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigzag(root, 0);
        return list;
    }
};