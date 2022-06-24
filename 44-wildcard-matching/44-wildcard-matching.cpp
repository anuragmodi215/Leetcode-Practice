class Solution {
public:
    bool helper(string&s, string&p, int n, int m, vector<vector<int>>&dp){
        if(n<0 and m<0) return true;
        if(n<0 and m>=0){
            for(int i=0; i<=m; i++){
                if(p[i]!='*') return false;
            }
            return true;
        }
        if(n>=0 and m<0) return false;
        
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==p[m] or p[m]=='?'){
            return dp[n][m] = helper(s,p,n-1,m-1,dp);
        }
        else{
            if(p[m]=='*'){
                return dp[n][m]=helper(s,p,n-1,m,dp) or helper(s,p,n,m-1,dp);
            }
            else return false;
        }
    }
    bool isMatch(string s, string p) {
     
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s,p,n-1,m-1,dp);
    }
};