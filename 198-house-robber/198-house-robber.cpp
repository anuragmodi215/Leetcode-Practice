class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int>dp(n+1,-1);
        dp[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            int a = nums[i];
            if(i-2>=0){
                a = a+dp[i-2];
            }
            int b = dp[i-1];
            dp[i] = max(a,b);
        }
        return dp[n];
    }
};