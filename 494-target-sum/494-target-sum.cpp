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
        
      
        if(arr_sum<abs(target) or (arr_sum+target)%2==1) return 0;
        return helper(nums,nums.size(),sumi);
    }
};


/*
First Condition :
If the total sum of the array is less than the target sum, then in no any way we can get the target sum.
Second Condition :
Basically here we are splitting array into two subarrays. One having + sign and other having - sign. Let the sum of first subarray be S1 and sum of second array be S2.
S1 + S2 = Sum(sum of the array)
S1 - S2 = Target
2S1 = Sum + Target
S1 = (Sum + Target)/2
Thus, sum + target should be an even number.
*/
