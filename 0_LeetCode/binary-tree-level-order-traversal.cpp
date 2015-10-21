/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        
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
            rt_val.push_back(row); row.clear();  // Add current row to result
            cur.clear(); cur = nxt; nxt.clear(); // Next -> Current row
        }
        
        return rt_val;
    }
};