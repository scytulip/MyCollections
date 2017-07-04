/*
366. Find Leaves of Binary Tree My Submissions QuestionEditorial Solution
Total Accepted: 138 Total Submissions: 253 Difficulty: Medium
Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Remove the leaves [4, 5, 3] from the tree

          1
         / 
        2          
2. Remove the leaf [2] from the tree

          1          
3. Remove the leaf [1] from the tree

          []         
Returns [4, 5, 3], [2], [1].

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root==NULL) return list;
        search(root);
        return list;
    }
private:
    vector<vector<int>> list;
    
    int search(TreeNode* root) {
        if (root==NULL) return -1;
        
        int idx = max(search(root->left), search(root->right))+1;
        
        if (idx==list.size()) list.push_back(vector<int>());
        
        list[idx].push_back(root->val);
        
        return idx;
    }
};