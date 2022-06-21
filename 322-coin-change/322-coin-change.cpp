class Solution {
public:
    int helper(vector<int>& coins, int index, int amount,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(index==0){
            if(amount%coins[index]==0){
                return amount/coins[index];
            }
            else return INT_MAX-1;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        int notTake = 0+helper(coins,index-1,amount,dp);
        int take = INT_MAX;
        if(coins[index]<=amount){
            take = 1+helper(coins,index,amount-coins[index],dp);
        }
        return dp[index][amount] = min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = helper(coins,n-1,amount,dp);
        if(ans==INT_MAX-1) return -1;
        return ans;
    }
};