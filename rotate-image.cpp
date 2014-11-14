class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        
        int len = matrix.size();
        int i,j,swp;
        
        for (i=0; i<len/2; i++)
        {
            for (j=i; j<(len-i-1); j++) 
            {
                swp = matrix[j][len-i-1];
                matrix[j][len-i-1] = matrix[i][j]; // Up to right
                matrix[i][j] = matrix[len-j-1][i];   // Left to up
                matrix[len-j-1][i] = matrix[len-i-1][len-j-1]; // Bottom to left
                matrix[len-i-1][len-j-1] = swp; // Right to bottom
            }
        }
        
    }
};