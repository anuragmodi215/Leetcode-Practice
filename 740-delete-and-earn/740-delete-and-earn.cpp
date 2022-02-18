class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(20005);
        vector<int>dp(10005);
        int maxi=INT_MIN;
        for(auto &i:nums){
            freq[i]++;
            maxi=max(maxi,i);
        }
        dp[1]=freq[1];
        dp[2]=max(freq[1],freq[2]*2);
        for(int i=3; i<10005; i++){
            dp[i]=max(dp[i-1],(freq[i]*i+dp[i-2]));
        }
        return dp[maxi];
    }
};