class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        // return helper(grid,n-1,m-1,dp);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 and j==0) dp[i][j]=grid[i][j];
                else{
                    int left=INT_MAX;
                    int right=INT_MAX;
                    if(i>0) left = grid[i][j]+dp[i-1][j];
                    if(j>0) right = grid[i][j]+dp[i][j-1];
                    dp[i][j] = min(left,right);
                }
            }
        }
        return dp[n-1][m-1];
    }
};