/*
255. Verify Preorder Sequence in Binary Search Tree My Submissions QuestionEditorial Solution
Total Accepted: 8934 Total Submissions: 23888 Difficulty: Medium
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty()) return true;
        return check(preorder, 0, preorder.size(), INT_MAX, true);
    }
private:
    bool check(vector<int>& preorder, int lo, int up, int root, bool left) {
        if (lo>=up) return true;
        
        // [lo,up)
        for (int i=lo; i<up; ++i) {
            if (left && preorder[i]>root) return false;
            if (!left && preorder[i]<root) return false;
        }
        
        root = preorder[lo];
        int i = lo;
        while(i!=up && preorder[++i]<root); 
        
        return check(preorder, lo+1, i, root, true) &&
                check(preorder, i, up, root, false);
    }
};