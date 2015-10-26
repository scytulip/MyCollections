class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, 0));
        int up = 0;
        int left = 0;
        int right = n-1;
        int down = n-1;
        int count = 1;
        int i,j;
        
        while(1)
        {
            for (i=left; i<=right; i++) mat[up][i] = (count ++);
            up ++; if (count > n*n) break;
            for (i=up; i<=down; i++) mat[i][right] = (count ++);
            right --; if (count > n*n) break;
            for (i=right; i>=left; i--) mat[down][i] = (count ++);
            down --; if (count > n*n) break;
            for (i=down; i>=up; i--) mat[i][left] = (count ++);
            left ++; if (count > n*n) break;
        }
        
        return mat;
    }
};