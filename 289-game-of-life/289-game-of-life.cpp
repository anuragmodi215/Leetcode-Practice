class Solution {
public:
    int dx[8] = {0,0,1,-1,-1,-1,1,1};
    int dy[8] = {1,-1,0,0,-1,1,-1,1};
    bool isSafe(vector<vector<int>>& board, int i, int j){
        int n=board.size();
        int m=board[0].size();
        if(i>=0 and j>=0 and i<n and j<m and board[i][j]==1) return true;
        return false;
    }
    void countNeighbours(vector<vector<int>>& board, int i, int j, vector<vector<int>>&neig){
        int liveNeig=0;
        //cout<<i<<" "<<j<<"-> ";
        for(int k=0; k<8; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(isSafe(board,x,y)){
                //cout<<"("<<x<<" "<<y<<")";
                liveNeig++;
            }
        }
        //cout<<endl;
        neig[i][j] = liveNeig;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>neig(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                countNeighbours(board,i,j,neig);
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout<<neig[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==1){
                    if(neig[i][j]<2){
                        board[i][j]=0;
                    }
                    else if(neig[i][j]>=2 and neig[i][j]<=3){
                        board[i][j]=1;
                    }
                    else board[i][j]=0;
                }
                else if(board[i][j]==0){
                    if(neig[i][j]==3){
                        board[i][j]=1;
                    }
                }
            }
        }
    }
};