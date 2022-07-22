class Solution {
public:
    int helper(string &a, string&b, int n, int m, vector<vector<int>>&dp){
        if(n<0){
            return m+1;
        }
        if(m<0){
            return n+1;
        }
        if(n<0 and m<0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        if(a[n]==b[m]){
            return dp[n][m]=helper(a,b,n-1,m-1,dp);
        }
        
        else{
            //replacement
            int replacement = 1+helper(a,b,n-1,m-1,dp);
            //insert
            int insert = 1+helper(a,b,n,m-1,dp);
            //delete
            int deletion = 1+helper(a,b,n-1,m,dp);
            return dp[n][m] = min(replacement,min(insert,deletion));
        }
        return 0;
    }
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(a,b,n-1,m-1,dp);
    }
};