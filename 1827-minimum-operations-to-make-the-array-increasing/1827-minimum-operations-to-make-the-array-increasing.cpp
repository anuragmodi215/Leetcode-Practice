class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1; i<n; i++){
            if(nums[i-1]==nums[i]){
                nums[i]=nums[i]+1;
                cnt++;
            }
            else if(nums[i-1]>nums[i]){
                int diff = nums[i-1]-nums[i]+1;
                nums[i] = nums[i]+diff;
                cnt+=diff;
            }
        }
        return cnt;
    }
};