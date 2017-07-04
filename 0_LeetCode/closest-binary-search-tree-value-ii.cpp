/*
272. Closest Binary Search Tree Value II  QuestionEditorial Solution  My Submissions
Total Accepted: 7815
Total Submissions: 22279
Difficulty: Hard
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Hint:

Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much easier.
Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor node separately.
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
class mycompare {
public:
    bool operator() (const pair<double, int>& a, const pair<double, int>& b) const {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        ScanTree(root, target);
        vector<int> result(k, 0);
        for (int i=0; i<k; ++i) {
            result[i] = que.top().second;
            que.pop();
        }
        return result;
    }
private:
    priority_queue<double, std::vector<pair<double, int>>, mycompare> que;
    void ScanTree(TreeNode* root, const double& target) {
        if (root == nullptr) {
            return;
        } else {
            ScanTree(root->left, target);
            ScanTree(root->right, target);
            que.emplace(abs(root->val-target), root->val);
        }
    }
};