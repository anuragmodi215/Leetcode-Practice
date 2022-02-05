class Solution {
public:
    int helper(string &text1, int n, string &text2, int m, vector<vector<int>>&dp){
        if(n==0 or m==0) return 0;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(text1[n-1]==text2[m-1]){
            return dp[n][m] = 1+helper(text1,n-1, text2,m-1,dp);
        }
        else{
            int x=helper(text1,n-1,text2,m,dp);
            int y=helper(text1,n,text2,m-1,dp);
            dp[n][m]=max(x,y);
            return max(x,y);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                dp[i][j]=-1;
            }
        }
        //for(int i=0; i<)
        return helper(text1,n,text2,m,dp);
    }
};