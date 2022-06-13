class Solution {
public:
    int helper(int row,int col,int output,int n,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(row==n-1) return triangle[row][col];
        if(dp[row][col]!=-1)return dp[row][col];
        int one = triangle[row][col]+helper(row+1,col,output,n,triangle,dp);
        int onePlus = triangle[row][col]+helper(row+1,col+1,output,n,triangle,dp);
        return dp[row][col]= min(one,onePlus);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,0,0,n,triangle,dp);
        // return [row][col];
    }
};
    