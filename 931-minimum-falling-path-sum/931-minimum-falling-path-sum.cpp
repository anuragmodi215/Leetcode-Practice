class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp,int n, int m){
        if(j<0 or j>=m) return INT_MAX-110;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = matrix[i][j]+helper(i-1,j,matrix,dp,n,m);
        int upRight = matrix[i][j]+helper(i-1,j+1,matrix,dp,n,m);
        int upLeft = matrix[i][j]+helper(i-1,j-1,matrix,dp,n,m);
        
        return dp[i][j] = min(up,min(upRight,upLeft));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini=INT_MAX;
        for(int j=0; j<m; j++){
            mini = min(mini,helper(n-1,j,matrix,dp,n,m));
        }
        return mini;
    }
};