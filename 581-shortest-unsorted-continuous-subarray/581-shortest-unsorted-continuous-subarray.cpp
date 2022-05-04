class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int left=-1,right=-1;
        int n=nums.size();
        for(int i=0; i<n; i++){
            maxi = max(nums[i],maxi);
            if(maxi>nums[i]){
                right=i;
            }
        }
        for(int i=n-1; i>=0; i--){
            mini = min(nums[i],mini);
            if(mini<nums[i]){
                left=i;
            }
        }
        if(left==right) return 0;
        return right-left+1;
    }
};