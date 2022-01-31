class Solution {
public:
//     int helper(vector<int>& cost, int n){
//         if(n<0) return 0;
        
//         int x=helper(cost,n-1)+cost[n];
//         int y=helper(cost,n-2)+cost[n];
        
//         return min(x,y);
//     }
    
    int minCostClimbingStairs(vector<int>& cost) {
           int n=cost.size();
        // int x=helper(cost,n-1);
        // int y=helper(cost,n-2);
        
            vector<int>dp(n);
            dp[0]=cost[0];
            dp[1]=cost[1];
            for(int i=2; i<n; i++){
                dp[i]=min(dp[i-1],dp[i-2])+cost[i];
            }
        return min(dp[n-1],dp[n-2]);
        //return min(x,y);
    }
};