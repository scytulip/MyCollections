class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        vector<vector<int>> counter(m, vector<int>(n,0));
    
        
        int max = 0;
        int i,j;
        for (i=0; i<m; ++i) {
            for (j=0; j<n; ++j) {
                if (matrix[i][j]=='1') {
                    counter[i][j] = PickMin(counter,i,j) + 1;
                    if (counter[i][j]>max) max = counter[i][j];
                } else {
                    counter[i][j]=0;
                }
            }
        }
        
        return max*max;
    }
private:
    // min([a-1][b],[a-1][b-1],[a][b-1])
    int PickMin(const vector<vector<int>>& ct, const int& a, const int& b) {
        if (a-1<0 || b-1<0) 
            return 0;
        else {
            int min = ct[a-1][b];
            min = (ct[a-1][b-1]<min) ? ct[a-1][b-1] : min;
            min = (ct[a][b-1]<min) ? ct[a][b-1] : min;
            return min;
        }
    }
};