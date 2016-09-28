class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if (!word.size()) return false;
        m = board.size();
        if (!m) return false;
        n = board[0].size();
        
        // Pre-processing
        /*
        proc = vector<bool>(26,false);
        for (int x=0; x<m; ++x){
            for (int y=0; y<n; ++y) {
                proc[board[x][y]-'a'] = true;
            }
        }
        for (auto c:word) if (!proc[c]) return false;
        */        
        // Start finding
        used = vector<vector<bool>>(m, vector<bool>(n, false));
        flag = false;
        for (int x=0; x<m; ++x) {
            for (int y=0; y<n; ++y) {
                if (word[0]==board[x][y]) {
                    start(x,y,0,word,board);
                }
                if (flag) return true;
            }
        }
        return false;
    }
private:
    //vector<bool> proc;
    vector<vector<bool>> used;
    bool flag;
    int m,n;
    
    void start(int x, int y, int idx, const string& word, const vector<vector<char>>& board) {
        if (idx==word.size()-1) {
            flag = true;
            return;
        }
        
        used[x][y] = true;
        
        if (x-1>=0 && !used[x-1][y] && board[x-1][y]==word[idx+1]) start(x-1,y,idx+1,word,board);
        if (flag) return;
        if (x+1<m && !used[x+1][y] && board[x+1][y]==word[idx+1]) start(x+1,y,idx+1,word,board);
        if (flag) return;
        
        if (y-1>=0 && !used[x][y-1] && board[x][y-1]==word[idx+1]) start(x,y-1,idx+1,word,board);
        if (flag) return;
        if (y+1<n && !used[x][y+1] && board[x][y+1]==word[idx+1]) start(x,y+1,idx+1,word,board);
        if (flag) return;
        
        used[x][y] = false;
    }
};