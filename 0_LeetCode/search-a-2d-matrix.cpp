class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a,b,idx,row;
        
        /* Search Row */
        a = 0; b = matrix.size()-1;
        while (b-a>1)
        {
            idx = (a+b)/2;
            if (matrix[idx][0]<target)
                a = idx;
            else
                b = idx;
        }
        if (matrix[b][0]>target) row = a; else row = b;
    
        /* Search Column */
        a = 0; b = matrix[row].size()-1;
        while (b-a>1)
        {
            idx = (a+b)/2;
            if (matrix[row][idx]<target)
                a = idx;
            else
                b = idx;
        }
        return (matrix[row][a]==target || matrix[row][b]==target);
    }
};