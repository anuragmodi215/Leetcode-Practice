class Solution {
public:
    bool isSafe(int row, int col, int n,vector<string>&board ){
        int drow=row,dcol=col;
        int urow=row,ucol=col;
        
        while(urow>=0 and ucol>=0){
            if(board[urow][ucol]=='Q'){
                return false;
            }
            urow--;ucol--;
        }
        urow = row, urow = col;
        while(drow<n and dcol>=0){
            if(board[drow][dcol]=='Q'){
                return false;
            }
            drow++;dcol--;
        }
        for(int j=col; j>=0; j--){
            if(board[row][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void helper(int col, int n, vector<string>&board, vector<vector<string>>&ans){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row = 0; row<n; row++){
            if(isSafe(row,col,n,board)){
                board[row][col] = 'Q';
                helper(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
     
        string s(n,'.');
        vector<string>board(n,s);
        vector<vector<string>>ans;
        helper(0,n,board,ans);
        return ans;
        
    }
};