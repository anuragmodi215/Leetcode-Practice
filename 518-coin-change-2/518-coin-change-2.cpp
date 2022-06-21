class Solution {
public:
    int helper(vector<int>&coins,int ind, int amount, vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(ind==0){
            if(amount%coins[0]==0) return 1;
            else return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = helper(coins,ind-1, amount,dp);
        int take = 0;
        if(coins[ind]<=amount){
            take = helper(coins,ind,amount-coins[ind],dp);
        }
        return dp[ind][amount] = notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(coins,n-1,amount,dp);
    }
};