class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int maxpro=nums[0], minpro=nums[0],ans=nums[0];
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]<0) swap(maxpro,minpro);
            maxpro=max(nums[i],maxpro*nums[i]);
            minpro=min(nums[i],minpro*nums[i]);
            ans=max(ans,maxpro);
        }
        return ans;
    }
};