class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int maxs=INT_MIN;
        long long int sum=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
              
                     sum=sum+nums[j];
               
                maxs=max(maxs,sum);
               
            }
             sum=0;
            
        }
        return maxs;
    }
};