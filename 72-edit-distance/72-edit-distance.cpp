class Solution {
public:
    
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j=1; j<=m; j++){
            dp[0][j] = j;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    int replacement = 1+dp[i-1][j-1];
                    int insert = 1+dp[i][j-1];
                    int deletion = 1+dp[i-1][j];
                    dp[i][j] = min(replacement,min(insert,deletion));
                }
            }
        }
        return dp[n][m];
    }
};