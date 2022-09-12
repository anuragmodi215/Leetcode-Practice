class Solution {
public:
    int helper(vector<int>& tokens,int power, int i, int j,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,notTake=0;
        if(tokens[i]<=power){
            take = helper(tokens,power-tokens[i],i+1,j,dp)+1;
        }
        if(take){
            notTake = helper(tokens,power+tokens[j],i,j-1,dp)-1;
        }
        return dp[i][j] = max(notTake,take);
    }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(tokens,power,0,n-1,dp);
    }
};