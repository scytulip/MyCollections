class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> island(m, vector<int>(n, 0));
        int index = 0;
        vector<int> uni = {-1};
        int id_u, id_l;
        
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) if (grid[i][j]=='1') {
                id_u = (i-1<0) ? 0 : island[i-1][j];
                id_l = (j-1<0) ? 0 : island[i][j-1];
                if (id_u==id_l) {
                    if (id_u==0) {
                        ++index;
                        uni.push_back(index);
                        island[i][j] = index;
                    } else {
                        island[i][j] = id_u;
                    }
                } else {
                    if (id_u==0)
                        island[i][j] = id_l;
                    else if (id_l==0)
                        island[i][j] = id_u;
                    else {
                        island[i][j] = min(id_u, id_l);
                        uni[max(id_u, id_l)] = min(id_u, id_l);
                    }
                }
            }
        }
        
        for (int i=m-1; i>=0; --i) {
            for (int j=n-1; j>=0; --j) if (grid[i][j]=='1') {
                id_u = (i+1==m) ? 0 : island[i+1][j];
                id_l = (j+1==n) ? 0 : island[i][j+1];
                if (id_u==id_l) {
                    if (id_u!=0) {
                        island[i][j] = id_u;
                    }
                } else {
                    if (id_u==0)
                        island[i][j] = id_l;
                    else if (id_l==0)
                        island[i][j] = id_u;
                    else {
                        island[i][j] = min(id_u, id_l);
                        uni[max(id_u, id_l)] = min(id_u, id_l);
                    }
                }
            }
        }
        
        int count = 0;
        for (int i=0; i<uni.size(); ++i)
            if (uni[i]==i) ++count;
        
        return count;
    }
};