class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            
            int left = i+1;
            int right = n-1;
            
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                
                if(sum>0){
                    right--;
                }
                else if(sum<0){
                    left++;
                }
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right and nums[left]==nums[left+1]){
                        left++;
                    }
                    left++;
                    while(right>left and nums[right]==nums[right-1]){
                        right--;
                    }
                    
                    right--;
                }
            }
        }
        return ans;
    }
};