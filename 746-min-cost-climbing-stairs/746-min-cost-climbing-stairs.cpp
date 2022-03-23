class Solution {
public:
    int helper(vector<int>& cost, int n, vector<int>&dp){
        if(n<0) return 0;
        //if(n==0) return cost[0];
        if(dp[n]!=-1) return dp[n];
        int a = cost[n]+helper(cost,n-1,dp);
        int b = cost[n]+helper(cost,n-2,dp);
        return dp[n]=min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        int a = helper(cost,n-1,dp);
        int b = helper(cost,n-2,dp);
        return min(a,b);
    }
};