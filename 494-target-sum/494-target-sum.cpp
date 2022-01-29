class Solution {
public:
    int helper(vector<int>& nums, int n, int sum){
        cout<<12<<endl;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<1; j++){
                dp[i][j]=1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int arr_sum=0;
        
        for(auto i:nums) arr_sum+=i;
        int sumi=(arr_sum+target)/2;
        
        if(nums.size()==1){
            if(nums[0]==abs(target)) return 1;
        }
        if(arr_sum<abs(target) or (arr_sum+target)%2==1) return 0;
        return helper(nums,nums.size(),sumi);
    }
};