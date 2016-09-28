class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        cand_ = candidates;
        sort(cand_.begin(), cand_.end());
        search(-1, target);
        return list_;
    }
private:
    vector<int> cand_;
    vector<int> cur_;
    vector<vector<int>> list_;
    
    void search(int index, int residue) {
        if (0==residue) {
            list_.push_back(cur_);
            return;
        }
        
        int prev = -1;
        int val;
        for (int i = index+1; i<cand_.size(); ++i) {
            if (cand_[i]!=prev) {
                prev = cand_[i];
                val = residue-cand_[i];
                if (val>=0) {
                    cur_.push_back(cand_[i]);
                    search(i, val);
                    cur_.pop_back();
                } else {
                    break;
                }
            }
        }
    }
};