class Solution {
public:
//     int helper(vector<int>& coins, int amount,int n){
//         if(amount==0) return 0;
//         if(n==0) return INT_MAX-1;
        
//         if(coins[n-1]<=amount){
//              int take=1+helper(coins,amount-coins[n-1],n);
//              int notTake=helper(coins,amount,n-1);
           
//             return min(take,notTake);
//         }
//         else{
//             return helper(coins,amount,n-1);
//         }
//     }
    
    
    int helper(vector<int>& coins, int amount,int n){
       vector<vector<int>>dp(n+1, vector<int>(amount+1));
       
        for(int i=0; i<1; i++){
            for(int j=1; j<amount+1; j++){
                dp[i][j]=INT_MAX-1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
                if(coins[i-1]<=j){
                    int take=1+dp[i][j-coins[i-1]];
                    int notTake=dp[i-1][j];
                    dp[i][j]=min(take,notTake);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount];
    }
    
     
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int x= helper(coins,amount,n);
        if(x==INT_MAX-1) return -1;
        else return x;
    }
};