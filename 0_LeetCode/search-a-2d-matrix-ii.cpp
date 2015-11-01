class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int a,b,i;
        int sta,end,mid;
        int n = matrix[0].size();
        
        a = 0;
        b = matrix.size()-1;
        while(b-a>1)
        {
            mid = (a+b)/2;
            if (matrix[mid][0]<target)
                a = mid;
            else
                b = mid;
        }
        end = b;
        
        a = 0;
        b = matrix.size()-1;
        while(b-a>1)
        {
            mid = (a+b)/2;
            if (matrix[mid][n-1]>target)
                b = mid;
            else
                a = mid;
        }
        sta = a;
        
        for (i=sta; i<=end; i++)
        {
            a = 0;
            b = n-1;
            while (b-a>1)
            {
                mid = (a+b)/2;
                if (matrix[i][mid]<target)
                    a = mid;
                else
                    b = mid;
            }
            if (matrix[i][a]==target || matrix[i][b]==target)
                return true;
        }
        return false;
    }
};