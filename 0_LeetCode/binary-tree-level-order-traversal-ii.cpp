/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

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
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
               
        vector<vector<int>> rt_val;         // Return value
        vector<int> row;                    // Current row of numbers
        vector<TreeNode *> cur, nxt;        // Current row, next row
        vector<TreeNode *>::iterator i;
        
        if (root==NULL) return rt_val;
        else cur.push_back(root);
        
        while (!cur.empty())
        {
            for (i=cur.begin(); i!=cur.end(); i++)
            {
                row.push_back((*i)->val);   // Add current row's numbers to result
                if ((*i)->left!=NULL) nxt.push_back((*i)->left);
                if ((*i)->right!=NULL) nxt.push_back((*i)->right);
            }
            rt_val.insert(rt_val.begin(),row); row.clear();  // Add current row to result
            cur.clear(); cur = nxt; nxt.clear(); // Next -> Current row
        }
        
        return rt_val;
        
    }
};