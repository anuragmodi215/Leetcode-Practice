class Solution {
public:
    bool helper(vector<int>& nums,int sum,int n){
        // if(sum==0) return;
        // if(n==0) return;
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<1; j++){
                dp[i][j]=true;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(j>=nums[i-1]){
                    dp[i][j]=dp[i-1][j-nums[i-1]] or dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum%2==1) return false;
        
        return helper(nums,sum/2,nums.size());
    }
};