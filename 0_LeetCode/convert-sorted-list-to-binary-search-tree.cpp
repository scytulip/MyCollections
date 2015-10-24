/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
private:
    vector<int> num;
    TreeNode* buildTree(int a, int b)
    {
        if (a>b) return NULL;
        if (a==b) return (new TreeNode(num[a]));
        
        int idx = (a+b)/2;
        TreeNode* root = new TreeNode(num[idx]);
        root->left = buildTree(a,idx-1);
        root->right = buildTree(idx+1,b);
        
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* node = head;
        while (node != NULL)
        {
            num.push_back(node->val);
            node = node->next;
        }
        return buildTree(0, num.size()-1);
    }
};