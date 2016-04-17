class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n==1) {
            vector<string> rt_val;
            rt_val.push_back("()");
            return rt_val;
        } else if (n==2) {
            vector<string> rt_val;
            rt_val.push_back("()()");
            rt_val.push_back("(())");
            return rt_val;
        } else {
            unordered_set<string> p_set;
            vector<string> left;
            vector<string> right;
            left = generateParenthesis(n-1);
            for (auto x : left) {
                p_set.insert('('+x+')');
            }
            for (int i=1; i<n; ++i) {
                left = generateParenthesis(i);
                right = generateParenthesis(n-i);
                for (auto x : left) {
                    for (auto y : right) {
                        p_set.insert(x+y);
                    }
                }
            }
            left.clear();
            for (auto k : p_set) {
                left.push_back(k);
            }
            return left;
        }
    }
};