class Solution {
public:
    int helper(int n, vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        long long int ans=0;
        for(int i=0; i<n; i++){
            long long int a = helper(i,dp);
            long long int b = helper(n-i-1,dp);
            ans = ans+(a*b);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};