class Solution {
private:
    vector<int> rec;
    vector<int> v_num;
    int v_len;
    vector<vector<int>> list;
    void insertElement(int idx)
    {
        if (idx==v_len)
        {
            list.push_back(rec);
        }
        
        int i;
        rec.push_back(v_num[idx]);
        for (i=idx+1; i<=v_len; i++)
        {
            if (i==idx+1 || i==v_len || v_num[i]!=v_num[i-1])
                insertElement(i);
        }
        rec.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        v_len = nums.size();
        v_num = nums;
        sort(v_num.begin(), v_num.end());
        
        int i;
        for (i=0; i<=v_len; i++)
        {
            if (i==0 || i==v_len || v_num[i]!=v_num[i-1])
                insertElement(i);
        }
        
        return list;
    }
};