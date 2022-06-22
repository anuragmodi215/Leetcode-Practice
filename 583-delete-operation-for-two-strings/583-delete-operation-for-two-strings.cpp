class Solution {
public:
    int lcs(string &s, string&t, int i, int j, vector<vector<int>>&dp){
        if(i<0 or j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]){
            return dp[i][j] = 1+lcs(s,t,i-1,j-1,dp);
        }
        return dp[i][j] = max(lcs(s,t,i-1,j,dp),lcs(s,t,i,j-1,dp));
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return m+n-2*(lcs(s,t,n-1,m-1,dp));
    }
};