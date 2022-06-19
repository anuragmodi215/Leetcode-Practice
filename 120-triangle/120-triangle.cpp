class Solution {
public:
    int helper(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>&dp,int n){
        if(col>=n) return 0;
        if(row==n){
            // return triangle[row][col];
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int down = triangle[row][col]+helper(triangle,row+1,col,dp,n);
        int downRight = triangle[row][col]+helper(triangle,row+1,col+1,dp,n);
        return dp[row][col] = min(down,downRight);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(triangle,0,0,dp,n);
    }
};