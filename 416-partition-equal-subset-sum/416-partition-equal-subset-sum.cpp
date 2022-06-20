class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n = nums.size();
        if(n<=1) return false;
        
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        //cout<<sum;
        if(sum%2==1) return false;
        
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        if(nums[0]<=sum) dp[0][nums[0]] = 1;
        
       for(int i=1; i<n; i++){
           for(int target=1; target<=sum; target++){
               int notTake = dp[i-1][target];
               int take=0;
               if(nums[i]<=target){
                   take = dp[i-1][target-nums[i]];
               }
               dp[i][target] = notTake or take;
           }
       }
       return dp[n-1][sum];
    }
};