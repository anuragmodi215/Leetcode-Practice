class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int best_sum=INT_MIN;
        long long int current_sum=0;
        
        for(int i=0; i<nums.size(); i++){
            current_sum = max((long long int)(nums[i]),current_sum+nums[i]);
            best_sum = max(best_sum,current_sum);
        }
        return best_sum;
    }
};