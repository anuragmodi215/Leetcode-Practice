class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            totalSum+=nums[i];
        }
        int target = totalSum-x;
        if(target<0) return -1;
        else if(target==0) return n;
        int i=0,j=0;
        int sum=0;
        int windowLength=0;
        int maxLength=0;
        while(j<n and i<n){
            if(sum+nums[j]<=target){
                sum+=nums[j];
                windowLength = j-i+1;
                if(sum==target){
                    maxLength = max(windowLength,maxLength);
                }
                j++;
            }
            else{
                sum-=nums[i];
                i++;
            }
        }
        if(maxLength==0) return -1;
        return n-maxLength;
    }
};