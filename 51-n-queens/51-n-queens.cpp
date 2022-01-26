class Solution {
public:
    bool isValid(int row, int col, vector<string>board, int n){
        int r=row;
        int c=col;
        
        for(int i=c; i>=0; i--){
            if(board[r][i]=='Q') return false;
        }
           
           // while(c>=0){
           //     if(board[r][c]=='Q') return false;
           //     c--;
           // }
           // c=col;
        while(r>=0 and c>=0){
            if(board[r][c]=='Q') return false;
            r--;c--;
        }
        r=row;
        c=col;
        while(r<n and c>=0){
            if(board[r][c]=='Q') return false;
            r++;c--;
        }
        return true;
    }
    void helper(int n,vector<string>&board,vector<vector<string>>&ans,int col){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n; row++){
            if(isValid(row,col,board,n)){
                board[row][col]='Q';
                helper(n,board,ans,col+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        helper(n,board,ans,0);
        return ans;
    }
};