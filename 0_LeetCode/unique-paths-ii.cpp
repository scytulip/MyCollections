class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid[0].size();
        if (n==0) return 0;
        
        int v[n] = {0};
        int i, j;
        int left;
        
        for (i=0; i<n; i++)
        {
            if (obstacleGrid[0][i]==1) break;
            v[i] = 1;
        }
        
        for (i=1; i<obstacleGrid.size(); i++)
        {
            if (obstacleGrid[i][0]) 
            {
                left = 0;
                v[0] = 0;
            }
            left = v[0];
                
            for (j=1; j<n; j++)
            {
                if (obstacleGrid[i][j])
                {
                    v[j] = 0;
                    left = 0;
                } else
                {
                    v[j] += left;
                    left = v[j];
                }
            }
        }
        
        return v[n-1];
    }
};