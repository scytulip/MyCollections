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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        vector<string> tmp;
        int i;
        
        if (root == NULL) 
            return path;
        else if (root->left == NULL && root->right == NULL)
        {
            path.push_back(to_string(root->val));
            return path;
        }
        
        tmp = binaryTreePaths(root->left);
        if (!tmp.empty()) path.insert(path.end(), tmp.begin(), tmp.end());
        tmp = binaryTreePaths(root->right);
        if (!tmp.empty()) path.insert(path.end(), tmp.begin(), tmp.end());
        
        if (!path.empty())
        {
            for (i=0; i<path.size(); i++)
            {
                path[i] = to_string(root->val) + "->" + path[i];
            }
        }
        
        return path;
        
    }
};