class Solution {
public:
    int helper(int n,vector<int>&dp){
       if(n==1) return dp[n]= 0;
       if(dp[n]!=-1) return dp[n];
        for(int i=1; i<n; i++){
            if(n%i==0){
               if(helper(n-i,dp)==0) return dp[n]= 1; 
            }
        }
        return dp[n]=0;
    }
    bool divisorGame(int n) {
        vector<int>dp(n+1,-1);
        helper(n,dp);
        return dp[n];
    }
};