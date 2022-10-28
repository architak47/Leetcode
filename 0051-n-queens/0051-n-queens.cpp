class Solution {
    bool isPossible(int row, int col, vector<string> board, int n){
        int copyrow = row;
        int copycol = col;
        
// Upper diagonal
        while(row >= 0 and col >= 0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        
        row = copyrow;
        col = copycol;
// Same column;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = copyrow;
        col = copycol;
// lower diagnal
        while(row < n and col >= 0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isPossible(row, col, board, n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<string> board(n);
        string str(n, '.');
        for(int i = 0; i < n; i++){
            board[i] = str;
        }
        solve(0,board,ans,n);
        return ans;
    }
};