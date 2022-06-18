class Solution {
public:
    int helper(vector<vector<int>>& grid,int n, int m, vector<vector<int>>&dp){
        if(n<0 or m<0) return (INT_MAX-110);
        if(n==0 and m==0) return grid[n][m];
        if(dp[n][m]!=-1) return dp[n][m];
        long long int up = grid[n][m]+helper(grid,n-1,m,dp);
        long long int left = grid[n][m]+helper(grid,n,m-1,dp);
        return dp[n][m] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(grid,n-1,m-1,dp);
    }
};