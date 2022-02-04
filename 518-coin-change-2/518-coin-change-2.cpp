class Solution {
public:
//     int solve(int amount, vector<int>& coins, int n){
//         if(amount==0) return 1;
//         if(n==0) return 0;
        
//         if(coins[n-1]<=amount){
//             int take=solve(amount-coins[n-1],coins,n);
//             int notTake=solve(amount, coins, n-1);
//             return take+notTake;
//         }
//         else return solve(amount, coins, n-1);
//     }
    int solve(int amount, vector<int>& coins, int n){
        vector<vector<int>>dp(n+1,vector<int>(amount+1));
        int take=0,notTake=0;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<1; j++){
                dp[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1]<=j){
                    take=dp[i][j-coins[i-1]];
                    notTake=dp[i-1][j];
                    dp[i][j]=take+notTake;
                }
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return solve(amount,coins,n);
    }
};