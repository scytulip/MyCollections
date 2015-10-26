class Solution {
private:
    int num;
    vector<vector<int>> list;
    vector<int> rec;
    void search(int idx, int lvl)
    {
        int i;
        if (lvl==0)
        {
            list.push_back(rec);
            return;
        } else
        {
            for (i=idx+1; i<num+1; i++)
            {
                rec.push_back(i);
                search(i, lvl-1);
                rec.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        num = n;
        search(0,k);
        return list;
    }
};