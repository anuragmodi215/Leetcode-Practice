class Solution {
public:
    vector<vector<string>> ans;
    public:
    bool isSafe(vector<string>board,int n, int cols, int row){
        int drw=row;
        int dcol=cols;
        while(dcol>=0){
            if(board[drw][dcol]=='Q') return false;
            dcol--;
        }
        drw=row;
        dcol=cols;
        while(drw>=0 and dcol>=0){
            if(board[drw][dcol]=='Q') return false;
            drw--;dcol--;
        }
        drw=row;
        dcol=cols;
        while(dcol>=0 and drw<n){
            if(board[drw][dcol]=='Q') return false;
            dcol--;drw++;
        }
        return true;
    }
public:
    void solve(vector<string>&board, int n, int cols){
        if(cols==n){
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(board,n,cols,row)){
                board[row][cols]='Q';
                solve(board,n,cols+1);
                board[row][cols]='.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        string s(n,'.');
        for(int i=0; i<n; i++){
            board[i]=s;
        }
        
        solve(board,n,0);
        return ans;
    }
};