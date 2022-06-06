class Solution {
public:
    int helper(int n, vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        for(int i=1; i*i<=n; i++){
            int x = 1 + helper(n-i*i, dp);
            ans = min(x,ans);
        }
        dp[n] = ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};