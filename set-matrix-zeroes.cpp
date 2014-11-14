class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        
        int m = matrix.size();
        if (m==0) return;
        
        int n = matrix[0].size();
        if (n==0) return;
        
        int i,j;
        bool r0, c0;
        
        r0 = false;
        c0 = false;
        
        for (i=1; i<m; i++) {if(matrix[i][0]==0) {c0=true; break;}}
        for (j=1; j<n; j++) {if(matrix[0][j]==0) {r0=true; break;}}
        if (matrix[0][0]==0) {c0=true;r0=true;}
        
        for (i=1; i<m; i++)     // And one by one (row)
        {
            for (j=1; j<n; j++)
            {
                if (matrix[i][j]==0) 
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (i=1; i<m; i++)
        {
            if (matrix[i][0]==0)
            {
                for (j=1; j<n; j++) matrix[i][j]=0;
            }
        }
        
        for (j=1; j<n; j++)
        {
            if (matrix[0][j]==0)
            {
                for (i=1; i<m; i++) matrix[i][j]=0;
            }
        }
        
        if (c0) for (i=0; i<m; i++) matrix[i][0]=0;
        if (r0) for (j=0; j<n; j++) matrix[0][j]=0;

    }
};