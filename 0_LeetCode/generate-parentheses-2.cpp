class Solution {
public:
    vector<string> generateParenthesis(int n) {
        addParenthesis(n, n, true);
        return rt_val;
    }
private:
    vector<int> p_count;
    vector<string> rt_val;
    
    // left - # of left parenthesis left
    // right - # of right parenthesis left
    // always left <= right
    void addParenthesis(int left, int right, bool flag) {
        
        if (flag && left==0) {
            string p_str;
            for (int i=0; i<p_count.size(); ++i) {
                for (int j=0; j<p_count[i]; ++j) p_str += (i%2)?')':'(';
            }
            rt_val.push_back(p_str);
            return;
        }
        
        if (flag) { // add # of left parenthesis
            for (int i=1; i<=left; ++i) {
                p_count.push_back(i);
                addParenthesis(left-i, right, false);
                p_count.pop_back();
            }
        } else { // add # of right parenthesis
            if (left!=0) {
                for (int i=left; i<right; ++i) {
                    p_count.push_back(right-i);
                    addParenthesis(left, i, true);
                    p_count.pop_back();
                }
            } else { // fast path for no left parenthesis left
                p_count.push_back(right);
                addParenthesis(0, 0, true);
                p_count.pop_back();
            }
        }
    }
};