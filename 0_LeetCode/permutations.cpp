class Solution {
private:
    bool* nset;
    vector<vector<int>> list;
    vector<int> rec;
    vector<int>* num;
    int len;
    
    void dfs(int n)
    {
        int i;
        
        if (n==len)
        {
            list.push_back(rec);
            return;
        }
        
        for (i=0; i<len; i++)
            if (!nset[i])
            {
                nset[i] = true;
                rec.push_back((*num)[i]);
                dfs(n+1);
                nset[i] = false;
                rec.pop_back();
            }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        num = &nums;
        len = nums.size();
        nset = new bool[len];
        dfs(0);
        delete[] nset;
        return list;
    }
};