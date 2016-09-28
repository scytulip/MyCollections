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
    int countNodes(TreeNode* root) {
        if (root==NULL) return 0;
        
        int val = 0;    // return value;
        int lvl = 0;    // # of levels
        int pow2 = 1;   // 2^lvl
        TreeNode* pt = root;
        while (pt!=NULL) {
            ++ lvl;
            pow2 *= 2;
            pt = pt->left;
        }
        if (checkRight(root)==lvl) {
            return pow2-1;
        } else {
            pow2 /= 2;
            val += (pow2-1);
        }
        
        int last_count = 0; // # of nodes in the last line
        pt = root;
        while(pt!=NULL) {
            if (checkRight(pt->left)!=lvl-1) {
                pt = pt->left;
            } else {
                pt = pt->right;
                last_count += (pow2/2);
            }
            pow2 /= 2;
            --lvl;
        }
        val += last_count;
        
        return val;
    }
private:
    int checkRight(TreeNode* root) {
        TreeNode* pt = root;
        int val = 0;
        while (pt!=NULL) {
            pt = pt->right;
            ++val;
        }
        return val;
    }
};