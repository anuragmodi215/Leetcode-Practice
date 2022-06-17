class Solution {
public:
    int helper(vector<int>&nums,vector<int>&dp,int n, int ind){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int a = nums[ind]+helper(nums,dp,n,ind+2);
        int b = helper(nums,dp,n,ind+1);
        return dp[ind] = max(a,b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(nums,dp,n,0);
    }
};