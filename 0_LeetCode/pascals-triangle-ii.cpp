class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        int tmp, old, len; // Cache the temp value
        int i,j;
        vector<int> row;
        
        rowIndex ++;
        
        row.push_back(1);
        if (rowIndex == 1) return row;
        
        row.push_back(1);
        if (rowIndex == 2) return row;
        
        for (i=3; i<=rowIndex; i++)
        {
            len = row.size();
            tmp = row[0];
            for (j=1; j<len; j++)
            {
                old = row[j];
                row[j] = tmp + row[j];
                tmp = old;
            }
            row.push_back(1);
        }
        
        return row;
    }
};