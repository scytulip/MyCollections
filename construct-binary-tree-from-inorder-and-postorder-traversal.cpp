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
    TreeNode *splitTree(vector<int> &inorder, vector<int> &postorder, int in_start, int post_start, int len)
    {
        TreeNode *rt_val;
        int root;
        int nlen;
        
        if (len==0) return NULL;
        if (len==1) return new TreeNode(inorder[in_start]);
        
        root = postorder[post_start+len-1];
        rt_val = new TreeNode(root);
        for (nlen=0; nlen<len; nlen++) // Find pivot inorder[in_start+i]
        {
            if (inorder[in_start+nlen]==root) break;
        }
        
        rt_val->left = splitTree(inorder, postorder, in_start, post_start, nlen);
        rt_val->right = splitTree(inorder, postorder, in_start+nlen+1, post_start+nlen, len-nlen-1);
        
        return rt_val;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return(splitTree(inorder, postorder, 0, 0, inorder.size()));
    }
};