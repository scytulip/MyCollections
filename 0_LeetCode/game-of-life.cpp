class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        
        vector<int> dx = {-1,-1,-1,0,1,1,1,0};
        vector<int> dy = {1,0,-1,-1,-1,0,1,1};
        int count,x,y,k;
        // Scan
        for (x=0; x<m; ++x) {
            for (y=0; y<n; ++y) {
                count = 0;
                for (k=0; k<8; k++) 
                    if ((x+dx[k]>=0) && (x+dx[k]<m) && (y+dy[k]>=0) && (y+dy[k]<n) &&
                        abs(board[x+dx[k]][y+dy[k]])==1) count ++;
                if (abs(board[x][y])==1 && (count<2 || count>3)) 
                    board[x][y] = -1; // Live cell dies
                else if (board[x][y]==0 && count==3)
                    board[x][y] = -2; // New live cell
            }
        }
        // Recover
        for (x=0; x<m; ++x) {
            for (y=0; y<n; ++y) {
                if (board[x][y]==-1) board[x][y] = 0;
                if (board[x][y]==-2) board[x][y] = 1;
            }
        }
    }
};