class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    int x=dp[i-1][j];
                    int y=dp[i][j-1];
                    dp[i][j]=max(x,y);
                }
            }
        }
        return dp[n][m];
    }
};