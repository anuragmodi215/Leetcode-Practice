class Solution {
public:
    int helper(int index, vector<int>&cost,vector<int>&dp,int n){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int oneStep = cost[index]+helper(index+1,cost,dp,n);
        int twoStep = cost[index]+helper(index+2,cost,dp,n);
        return dp[index]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        int first = helper(0,cost,dp,n);
        int second = helper(1,cost,dp,n);
        return min(first,second);
    }
};