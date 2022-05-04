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
                    vector<int>triplet{nums[i],nums[left],nums[right]};
                    ans.push_back(triplet);
                    while(left<right and nums[left]==triplet[1]){
                        left++;
                    }
                    //left++;
                    while(right>left and nums[right]==triplet[2]){
                        right--;
                    }
                    
                    //right--;
                }
            }
        }
        return ans;
    }
};