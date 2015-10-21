class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        
        int i,j;
        int old,tmp;
        vector<int> row;
        vector<vector<int>> rt_val;
        
        if (numRows<1) return rt_val; // Special Case numRows < 1
        
        row.push_back(1);
        rt_val.push_back(row);
        if (numRows==1) return rt_val;
        
        row.push_back(1);
        rt_val.push_back(row);
        if (numRows==2) return rt_val;
        
        for(i=3; i<=numRows; i++)
        {
            tmp = 1; old = 0;
            for (j=1; j<i-1; j++)
            {
                old = row[j];
                row[j] = tmp + row[j];
                tmp = old;
            }
            row.push_back(1);
            rt_val.push_back(row);
        }
        
        return rt_val;
    }
};