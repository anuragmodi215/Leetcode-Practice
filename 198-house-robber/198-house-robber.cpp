class Solution {
public:
    // int maxi=INT_MIN;
    // void helper(vector<int>& nums, int n, int sum){
    //     if(n<0){
    //         maxi=max(maxi,sum);
    //         return;
    //     }
    //     helper(nums,n-2,sum+nums[n]);
    //     helper(nums,n-1,sum);
    // }
    int rob(vector<int>& nums) {
        //maxi=INT_MIN;
        int n =nums.size();
        // helper(nums,n-1,0);
        // return maxi;
        
        vector<int>dp(n);
        dp[0]=nums[0];
        if(n>1)
            dp[1]=max(nums[0],nums[1]);
        if(n==2){
            return max(dp[0],dp[1]);
        }
        for(int i=2; i<n; i++){
            dp[i]=max((dp[i-2]+nums[i]),dp[i-1]);
        }
        return dp[n-1];
    }
};