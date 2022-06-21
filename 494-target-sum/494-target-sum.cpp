class Solution {
public:
    int helper(vector<int>& nums, int ind, int target, vector<vector<int>>&dp){
        if(ind==0){
            if(target==0 and nums[0]==0) return 2;
            if(target==0 or nums[0]==target) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake = helper(nums,ind-1,target,dp);
        int take = 0;
        if(nums[ind]<=target){
            take = helper(nums,ind-1,target-nums[ind],dp);
        }
        return dp[ind][target] = take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(auto i:nums)sum+=i;
        if(sum-target<0) return 0;
        if((sum-target)%2==1) return 0;
        target = (sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(nums,n-1,target,dp);
    }
};