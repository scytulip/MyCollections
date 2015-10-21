class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        
        int row = grid.size();
        if (row==0) return 0;
        
        int col = grid[0].size();
        if (col==0) return 0;
        
        int len = (row>col) ? row : col;
        int i,j;
        int a,b;
        
        for (i=1; i<len; i++)
        {
            for (j=0; j<i; j++)
            {
                if (i<row && j<col)
                {
                    if (i-1<0)
                        grid[i][j] += grid[i][j-1];
                    else if (j-1<0)
                        grid[i][j] += grid[i-1][j];
                    else
                        grid[i][j] += (grid[i-1][j]>grid[i][j-1]) ?
                                        grid[i][j-1] : grid[i-1][j];
                }
                
                if (j<row && i<col)
                {
                    if (j-1<0)
                        grid[j][i] += grid[j][i-1];
                    else if (i-1<0)
                        grid[j][i] += grid[j-1][i];
                    else
                        grid[j][i] += (grid[j-1][i]>grid[j][i-1]) ?
                                        grid[j][i-1] : grid[j-1][i];
                }
            }
            
            if (i<row && i<col)
            {
                grid[i][i] += (grid[i-1][i]>grid[i][i-1]) ?
                                grid[i][i-1] : grid[i-1][i];
            }
        }
        
        return grid[row-1][col-1];
    }
};