class Solution {
public:
    int findUniqueStairsCount(int n , vector<int>&dp){
        if(n==0 or n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int oneStep = findUniqueStairsCount(n-1,dp);
        int twoStep = findUniqueStairsCount(n-2,dp);
        return dp[n] = oneStep+twoStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return findUniqueStairsCount(n,dp);
        //return dp[n];
    }
};