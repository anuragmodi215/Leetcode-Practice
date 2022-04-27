class Solution {
public:
  
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        //vector<unordered_map<int,int>>dp(n);
        vector<vector<int>>dp(1000,vector<int>(1010,0));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int dif = nums[i]-nums[j]+500;
                dp[j][dif] = max(2,dp[i][dif]+1);
                res = max(res,dp[j][dif]);
            }
        }
        
        return res;
    }
};