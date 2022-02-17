class Solution {
public:
    int helper(vector<int>& nums, int n){
        if(n==0) return 0;
        
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1; i<n; i++){
            if(i-2>=0){
                dp[i]=max((dp[i-2]+nums[i]),dp[i-1]);
            }
            else{
                dp[i]=max(dp[i-1],nums[i]);
            }
        }
        
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n-1; i++)
            a.push_back(nums[i]);
        
        for(int i=1; i<n; i++){
            b.push_back(nums[i]);
        }
        int x=helper(a,n-1);
        int y=helper(b,n-1);
        return max(x,y);
    }
};