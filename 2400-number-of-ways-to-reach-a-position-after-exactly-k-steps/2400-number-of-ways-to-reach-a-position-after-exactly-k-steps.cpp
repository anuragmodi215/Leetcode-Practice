class Solution {
public:
    int mod = 1e9+7;
    int helper(int strt, int goal, int k, vector<vector<int>>&dp){
        
        if(strt==goal and k==0){
            return 1;
        }
        if(k==0) return 0;
        if(dp[strt+1000][k] != -1) return dp[strt+1000][k];
        
        int forward = helper(strt+1,goal,k-1,dp);
        int backward = helper(strt-1,goal,k-1,dp);
        int ans =  (forward+backward)%mod;
        return dp[strt+1000][k] = ans;
        //return -1;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>>dp(3001,vector<int>(k+1,-1));
        return helper(startPos,endPos,k,dp);
    }
};