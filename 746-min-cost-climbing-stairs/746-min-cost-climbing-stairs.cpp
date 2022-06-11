class Solution {
public:
    int helper(int index, vector<int>& cost, int n,vector<int>&dp){
        if(index==n-2 or index==n-1) return cost[index];
        if(dp[index]!=-1) return dp[index];
        int oneStep = helper(index+1,cost,n,dp)+cost[index];
        int twoStep = helper(index+2,cost,n,dp)+cost[index];
        return dp[index]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        int a = helper(0,cost,n,dp);
        int b = helper(1,cost,n,dp);
        return min(a,b);
    }
};