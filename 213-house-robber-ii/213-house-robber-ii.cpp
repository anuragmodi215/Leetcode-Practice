class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            if(i>1){
                dp[i]=max((dp[i-2]+nums[i]),(dp[i-1]));
            }
            else{
                dp[i]=max(dp[i-1],nums[i]);
            }           
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        
        vector<int>a;
        for(int i=0; i<n-1; i++) a.push_back(nums[i]);
        
        vector<int>b;
        for(int i=1; i<n; i++) b.push_back(nums[i]);
        
        return max(solve(a),solve(b));
    }
};