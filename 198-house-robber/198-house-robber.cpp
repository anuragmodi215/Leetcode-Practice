class Solution {
public:
    int helper(vector<int>&nums, int n,vector<int>&dp){
        if(n==0) return nums[n];
        if(dp[n]!=-1) return dp[n];
        int a = INT_MIN;
        a = nums[n];
        if(n-2>=0){
            a = a+helper(nums,n-2,dp);
        }
        int b = helper(nums,n-1,dp);
        return dp[n]=max(a,b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int>dp(n+1,-1);
        return helper(nums,n,dp);
    }
};