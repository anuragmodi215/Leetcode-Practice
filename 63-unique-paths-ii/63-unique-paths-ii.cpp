class Solution {
public:
    int helper(vector<vector<int>>& grid, int n, int m, vector<vector<int>>&dp){
        if(n<0 or m<0) return 0;
        if(n>=0 and m>=0 and grid[n][m]==1) return 0;
        if(n==0 and m==0) return 1;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        int left = helper(grid,n,m-1,dp);
        int up = helper(grid,n-1,m,dp);
        return dp[n][m] = left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);
    }
};