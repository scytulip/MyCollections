class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> myset;
        int i,j,a,b;
        
        for (i=0; i<9; i++)
        {
            myset.clear();
            for (j=0; j<9; j++)
                if (board[i][j]!='.')
                {
                    if (myset.find(board[i][j])!=myset.end()) return false;
                    myset.insert(board[i][j]);
                }
        }
        
        for (j=0; j<9; j++)
        {
            myset.clear();
            for (i=0; i<9; i++)
                if (board[i][j]!='.')
                {
                    if (myset.find(board[i][j])!=myset.end()) return false;
                    myset.insert(board[i][j]);
                }
        }
        
        for (a=0; a<3; a++)
        for (b=0; b<3; b++)
        {
            myset.clear();
            for (i=0; i<3; i++)
            for (j=0; j<3; j++)
                if (board[a*3+i][b*3+j]!='.')
                {
                    if (myset.find(board[a*3+i][b*3+j])!=myset.end()) return false;
                    myset.insert(board[a*3+i][b*3+j]);
                }
        }
        
        return true;
    }
};