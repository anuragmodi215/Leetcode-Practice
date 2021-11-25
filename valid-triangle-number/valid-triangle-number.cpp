class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=2; i<n; i++){
            int low=0,high=i-1;
            while(low<high){
                if(nums[low]+nums[high]>nums[i]){
                    ans=ans+(high-low);
                    high--;
                }
                else low++;
            }
        }
        return ans;
    }
};