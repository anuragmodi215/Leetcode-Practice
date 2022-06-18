class Solution {
public:
    int helper(int n, int m, vector<vector<int>>&dp){
        if(n<0 or m<0) return 0;
        if(n==0 and m==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        int up = helper(n-1,m,dp);
        int left = helper(n,m-1,dp);
        return dp[n][m]=up+left;
    }
    int uniquePaths(int n, int m) {
     
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,dp);
        
    }
};