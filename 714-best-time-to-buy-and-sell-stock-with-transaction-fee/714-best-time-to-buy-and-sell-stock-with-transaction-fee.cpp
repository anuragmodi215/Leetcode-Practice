class Solution {
public:
    int helper(vector<int>& prices, int n, int i, int fee,int canBuy,vector<vector<int>>&dp){
        if(i>=n) return 0;
        int &ans = dp[i][canBuy];
        if(ans!=-1) return ans;
        int ans1 = helper(prices,n,i+1,fee,canBuy,dp);
        int ans2=0;
        if(canBuy){
            ans2= -prices[i]+helper(prices,n,i+1,fee,0,dp);
        }
        else{
            ans2=prices[i]-fee+helper(prices,n,i+1,fee,1,dp);
        }
        return ans = max(ans1,ans2);
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,n,0,fee,1,dp);
    }
};