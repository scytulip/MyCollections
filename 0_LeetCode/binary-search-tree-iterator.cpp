/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if (root!=NULL) {
            nodes.push(root);
            status.push(0);
        }
        move();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!nodes.empty());
    }

    /** @return the next smallest number */
    int next() {
        int val = nodes.top()->val;
        move();
        return val;
    }
private:
    stack<TreeNode*> nodes;
    stack<int> status;
    
    void move() {
        while (!nodes.empty()) {
            switch (status.top()) {
                case 0: {
                    status.pop();
                    status.push(1);
                    if (nodes.top()->left!=NULL) {
                        nodes.push(nodes.top()->left);
                        status.push(0);
                    }
                    break;
                }
                case 1: {
                    status.pop();
                    status.push(2);
                    return;
                }
                case 2: {
                    status.pop();
                    status.push(3);
                    if (nodes.top()->right!=NULL) {
                        nodes.push(nodes.top()->right);
                        status.push(0);
                    }
                    break;
                }
                case 3: {
                    status.pop();
                    nodes.pop();
                }
            }
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */