class Solution {
private:
    vector<vector<int>> list; 
    vector<int> cand;
    vector<int> rec;
    void search(int target, int q)
    {
        int i;
        
        if (target==0)
        {
            list.push_back(rec);
            return;
        }
        
        int v;
        for (i=q; i<cand.size(); i++)
        {
            v = cand[i];
            if (v>target) break;
            rec.push_back(v);
            search(target-v,i);
            rec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        cand = candidates;
        sort(cand.begin(), cand.end());
        search(target,0);
        return list;
    }
};