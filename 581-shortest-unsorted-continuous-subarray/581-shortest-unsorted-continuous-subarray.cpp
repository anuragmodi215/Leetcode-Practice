class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     
        int n = nums.size();
        int left=0,right=n-1;
     
        while(left+1<n and nums[left]<=nums[left+1])left++;
        while(right-1>=0 and nums[right]>=nums[right-1])right--;
        
        if(left==n-1) return 0;
        
        int windowMini=INT_MAX;
        int windowMaxi=INT_MIN;
        for(int i=left; i<=right; i++){
            windowMini=min(nums[i],windowMini);
            windowMaxi=max(nums[i],windowMaxi);
        }
        //window k maximum se chota koi element hai right side mei toh right++
        //window k minimum se bada koi element hai left side mei toh left--;
        while(left-1>=0 and nums[left-1]>windowMini)left--;
        while(right+1<n and nums[right+1]<windowMaxi) right++;
        return right-left+1;
    }
};