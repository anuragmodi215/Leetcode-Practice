class Solution {
public:
    // int moveit(int i, int j, int row, int col, vector<vector<int>>&dp){
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(i==row-1 and j==col-1) return 1;
    //     int moves=0;
    //     if(i+1<row){
    //         moves= moves+moveit(i+1,j,row,col,dp);
    //         dp[i][j] = moves;
    //     }
    //     if(j+1<col){
    //         moves = moves+moveit(i,j+1,row,col,dp);
    //         dp[i][j] = moves;
    //     }
    //     return dp[i][j];
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,1));
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        //return moveit(0,0,m,n,dp);
    }
};