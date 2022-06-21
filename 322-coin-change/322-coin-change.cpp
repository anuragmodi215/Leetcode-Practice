class Solution {
public:
  
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        for(int i=0; i<n; i++) dp[i][0]=0;
        for(int j=0; j<=amount; j++){
            if(j%coins[0]==0){
                dp[0][j] = j/coins[0];
            }
            else{
                dp[0][j] = INT_MAX-1;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<=amount; j++){
                int notTake = dp[i-1][j];
                int take = INT_MAX;
                if(coins[i]<=j){
                    take = 1+dp[i][j-coins[i]];
                }
                dp[i][j] = min(notTake,take);
            }
        }
        int ans = dp[n-1][amount];
        if(ans == INT_MAX-1) return -1;
        return ans;
        
    }
};