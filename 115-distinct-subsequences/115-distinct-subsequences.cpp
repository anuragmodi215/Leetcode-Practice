class Solution {
public:
    int helper(string&s,string&t,int n, int m,vector<vector<int>>&dp){
        if(n<0 and m>=0) return 0;
        if(m<0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m] = helper(s,t,n-1,m-1,dp)+helper(s,t,n-1,m,dp);
        }
        else{
            return dp[n][m] = helper(s,t,n-1,m,dp);
        }
        return 0;
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s,t,n-1,m-1,dp);
    }
};