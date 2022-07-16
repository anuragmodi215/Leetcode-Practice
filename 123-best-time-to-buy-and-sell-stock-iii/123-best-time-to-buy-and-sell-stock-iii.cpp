class Solution {
public:
    int helper(vector<int>& prices, int cap, bool buy,int ind,vector<vector<vector<int>>>&dp){
        if(ind==prices.size() or cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap]=max(-prices[ind]+helper(prices,cap,0,ind+1,dp),helper(prices,cap,1,ind+1,dp));
        }
        else{
            return dp[ind][buy][cap]=max(prices[ind]+helper(prices,cap-1,1,ind+1,dp), helper(prices,cap,buy,ind+1,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int cap=2;
        bool buy=1;
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,cap,buy,0,dp);
    }
};