class Solution {
public:
    bool isValid(int i, int j, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        if(i<n and j<m and i>=0 and j>=0 and board[i][j]=='O'){
            return true;
        }
        return false;
    }
    void dfs(int i, int j, vector<vector<char>>& board){
        vector<pair<int,int>>dir{{1,0},{0,1},{-1,0},{0,-1}};
        for(int k=0; k<4; k++){
            if(board[i][j]=='O'){
                board[i][j]='B';
            }
            int dx = i+dir[k].first;
            int dy = j+dir[k].second;
            if(isValid(dx,dy,board)){
                dfs(dx,dy,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++){
            int j=0;
            if(isValid(i,j,board)){
                dfs(i,j,board);
            }
            j=m-1;
            if(isValid(i,j,board)){
                dfs(i,j,board);
            }
        }
        
        for(int j=0; j<m; j++){
            int i=0;
            if(isValid(i,j,board)){
                dfs(i,j,board);
            }
            i=n-1;
            if(isValid(i,j,board)){
                dfs(i,j,board);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='B'){
                    board[i][j]='O';
                }
            }
        }
    }
};


// [["X","X","X","X"],
//  ["X","O","O","X"],
//  ["X","X","O","X"],
//  ["X","B","X","X"]]

// [["X","X","X","X"],
//  ["X","X","X","X"],
//  ["X","X","X","X"],
//  ["X","O","X","X"]]









