class Solution {
public:
    bool IsPalindromic(int start, int end) {
        while (start<end) {
            if (str_[start] != str_[end]) return false;
            start ++;
            end --;
        }
        return true;
    }
    void Segment(int start) {
        if (start==strlen_) {
            pa_vec.push_back(cur_vec);
            return;
        }
        
        for (const auto& i : ch_table[str_[start]-'a']) {
            if (i>=start && IsPalindromic(start, i)) {
                cur_vec.push_back(str_.substr(start, i-start+1));
                Segment(i+1);
                cur_vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        str_ = s;
        strlen_ = str_.length();
        ch_table = vector<list<int>>(26, list<int>());
        for (int i; i<strlen_; ++i) ch_table[s[i]-'a'].push_back(i);
        Segment(0);
        return pa_vec;
    }
private:
    vector<vector<string>> pa_vec;
    vector<string> cur_vec;
    string str_;
    int strlen_;
    vector<list<int>> ch_table;
};