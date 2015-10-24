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
    TreeNode *createTree(vector<int> &num, int start, int end)
    {
        TreeNode *rt_val;
        int idx = (start+end)/2;
        
        if (start>end)
            return NULL;
        else if (start==end)
        {
            rt_val = new TreeNode(num[idx]);
        } else
        {
            rt_val = new TreeNode(num[idx]);
            rt_val->left = createTree(num, start, idx-1);
            rt_val->right = createTree(num, idx+1, end);
        }
        
        return rt_val;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return(createTree(num,0,num.size()-1));
    }
};

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
    vector<int> *num;
    TreeNode* buildTree(int a, int b)
    {
        if (a>b) return NULL;
        if (a==b) return (new TreeNode((*num)[a]));
        
        int idx = (a+b)/2;
        TreeNode* root = new TreeNode((*num)[idx]);
        root->left = buildTree(a,idx-1);
        root->right = buildTree(idx+1,b);
        
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        num = &nums;
        return buildTree(0, nums.size()-1);
    }
};