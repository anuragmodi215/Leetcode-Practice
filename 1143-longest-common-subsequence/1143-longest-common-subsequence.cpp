class Solution {
public:
    int helper(string &a, string &b, int n, int l, vector<vector<int>>&dp){
        if(n<0 or l<0) return 0;
        if(dp[n][l]!=-1) return dp[n][l];
        if(a[n]==b[l]){
            return dp[n][l] = 1+helper(a,b,n-1,l-1,dp);
        }
        return dp[n][l] = 0+max(helper(a,b,n-1,l,dp),helper(a,b,n,l-1,dp));
    }
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int l = b.size();
        vector<vector<int>>dp(n,vector<int>(l,-1));
        return helper(a,b,n-1,l-1,dp);
    }
};