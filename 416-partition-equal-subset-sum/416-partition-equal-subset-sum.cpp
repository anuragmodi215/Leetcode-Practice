class Solution {
public:
    bool helper(vector<int>&nums,int index, int target, vector<vector<int>>&dp){
        if(target==0) return true;
        if(index==0){
            if(nums[0]==target) return true;
            else return false;
        }
        if(dp[index][target]!=-1) return dp[index][target];
        int notTake = helper(nums,index-1,target,dp);
        int take = false;
        if(nums[index]<=target){
            take = helper(nums,index-1,target-nums[index],dp);
        }
        return dp[index][target] = take or notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        for(int i=0; i<n; i++) sum+=nums[i];
        if(sum%2==1) return false;
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return helper(nums,n-1,sum,dp);
    }
};