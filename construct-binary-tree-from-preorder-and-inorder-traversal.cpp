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
    TreeNode *splitTree(vector<int> &inorder, vector<int> &preorder, int in_start, int pre_start, int len)
    {
        TreeNode *rt_val;
        int root;
        int nlen;
        
        if (len==0) return NULL;
        if (len==1) return new TreeNode(inorder[in_start]);
        
        root = preorder[pre_start];
        rt_val = new TreeNode(root);
        for (nlen=0; nlen<len; nlen++) // Find pivot inorder[in_start+i]
        {
            if (inorder[in_start+nlen]==root) break;
        }
        
        rt_val->left = splitTree(inorder, preorder, in_start, pre_start+1, nlen);
        rt_val->right = splitTree(inorder, preorder, in_start+nlen+1, pre_start+nlen+1, len-nlen-1);
        
        return rt_val;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return(splitTree(inorder, preorder, 0, 0, inorder.size()));
    }
};