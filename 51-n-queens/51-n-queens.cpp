class Solution {
public:
    
    bool isSafe(vector<string>&board, int row, int col, int n){
        //cout<<row<<" "<<col<<endl;
        int fRow,fCol,bRow,bCol;
         //fRow = row;
         fCol = col;
         bRow = row;
         bCol = col;
        while(bRow>=0 and bCol>=0){
            if(board[bRow][bCol]=='Q') return false;
            bRow--;bCol--;
        }
         bRow = row;
         bCol = col;
        
        for(int i=bCol; i>=0; i--){
            if(board[row][i]=='Q') return false;
        }
        
        for(int i=bRow; i>=0 ; i--){
            if(board[i][col]=='Q') return false;
        }
        while(row<n and col>=0){
            if(board[row][col]=='Q') return false;
            row++;col--;
        }
        return true;
    }
    
    void solve(int col, int n, vector<string>&board,vector<vector<string>>&ans)
    {
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string>board(n);
        vector<vector<string>>ans;
        for(int i=0;  i<n; i++){
            board[i] = s;
        }
        //cout<<"funCall"<<endl;
        solve(0,n,board,ans);
        return ans;
    }
};