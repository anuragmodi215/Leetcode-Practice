class Solution {
public:
    int helper(vector<int>&nums,int target, vector<int>&dp){
        if(dp[target]!=-1) return dp[target];
        if(target==0) return 1;
        int res=0;
        for(int i=0; i<nums.size(); i++){
            if(target-nums[i]>=0){
                res+=helper(nums,target-nums[i],dp);
            }
        }
        return dp[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        helper(nums,target,dp);
        return dp[target];
    }
};