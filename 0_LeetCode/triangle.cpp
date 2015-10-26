class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int i,j,v1,v2;
        vector<int> min(triangle[row-1]);
        
        if (row==1) return min[0];
        
        for (i=row-1; i>=1; i--)
        {
            for (j=0; j<i; j++)
            {
                v1 = triangle[i-1][j]+min[j];
                v2 = triangle[i-1][j]+min[j+1];
                min[j] = (v1<v2) ? v1 : v2;
            }
        }
        
        return min[0];
    }
};