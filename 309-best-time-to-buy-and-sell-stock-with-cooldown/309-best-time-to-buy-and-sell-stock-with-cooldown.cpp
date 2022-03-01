class Solution {
public:
    int helper(vector<int>& prices, int n, int i, bool canBuy,vector<vector<int>>&dp){
        if(i>=n) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        int &ans=dp[i][canBuy];
        int ans1=helper(prices,n,i+1,canBuy,dp);
        int ans2=0;
        if(canBuy){
            ans2=-prices[i]+helper(prices,n,i+1,false,dp);
        }
        else{
            ans2=prices[i]+helper(prices,n,i+2,true,dp);
        }
        return ans = max(ans1,ans2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,-1));
        
        return helper(prices,prices.size(),0,true,dp);
        
        //return dp[prices.size()][]
    }
};