class Solution {
public:
    
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int l = b.size();
        vector<vector<int>>dp(n+1,vector<int>(l+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=l; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else dp[i][j] = 0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][l];
    }
};