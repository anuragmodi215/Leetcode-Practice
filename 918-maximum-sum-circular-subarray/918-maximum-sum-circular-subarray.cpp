class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum=nums[0],currMax=0,minSum=nums[0],currMin=0,tot=0;
        
        for(auto i:nums){
            currMax=max(currMax+i,i);
            maxSum=max(currMax,maxSum);
            
            currMin=min(currMin+i, i);
            minSum=min(currMin, minSum);
            
            tot+=i;
        }
        
        if(maxSum>0){
            return max(maxSum, tot-minSum);
        }
        return maxSum;
    }
};