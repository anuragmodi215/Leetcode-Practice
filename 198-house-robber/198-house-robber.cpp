class Solution {
public:
//     int helper(vector<int>& nums,int n){
//         if(n<0) return 0;
        
//         int sum=max((helper(nums,n-2)+nums[n]), helper(nums,n-1));
//         return sum;
//     }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        
        for(int i=1; i<n; i++){
            if(i>1)
                dp[i]=max((dp[i-2]+nums[i]),dp[i-1]);
            else
                dp[i]=max(dp[i-1],nums[i]);
        }
        //return helper(nums,nums.size()-1);
        return dp[n-1];
    }
};