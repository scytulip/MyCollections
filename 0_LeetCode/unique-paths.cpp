class Solution {
public:
    int uniquePaths(int m, int n) {
        int v[n] = {0};
        int i, j;
        int left;
        
        for (i=0; i<n; i++) v[i] = 1;
        
        for (i=1; i<m; i++)
        {
            left = 1;
            for (j=1; j<n; j++)
            {
                v[j] += left;
                left = v[j];
            }
        }
        
        return v[n-1];
        
    }
};