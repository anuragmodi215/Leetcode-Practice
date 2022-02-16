class Solution {
public:
    int helper(vector<int>cost,int n,vector<int>&dp){
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int x=helper(cost,n-1,dp)+cost[n];
        int y=helper(cost,n-2,dp)+cost[n];
        
        dp[n]=min(x,y);
        return min(x,y);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int x=helper(cost,n-1,dp);
        int y=helper(cost,n-2,dp);
        return min(x,y);
    }
};