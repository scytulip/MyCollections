/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private:
    vector<TreeLinkNode *> lvl;
    void travel(TreeLinkNode *root, int level)
    {
        if (root==NULL) return;
        
        if (level==lvl.size())
        {
            lvl.push_back(root);
        } else
        {
            lvl[level]->next = root;
            lvl[level] = root;
        }
        
        travel(root->left, level+1);
        travel(root->right, level+1);
    }
public:
    void connect(TreeLinkNode *root) {
        travel(root, 0);
    }
};