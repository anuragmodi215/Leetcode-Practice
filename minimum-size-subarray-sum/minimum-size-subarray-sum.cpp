class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0,ans=INT_MAX;
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum=sum+nums[i];
            while(sum>=target){
                ans=min(ans,i-j+1);
                sum=sum-nums[j++];
            }
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};