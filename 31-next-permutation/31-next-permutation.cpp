class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastIndex=-1;
        int n=nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]) lastIndex=i;
        }
        
        if(lastIndex==-1){
            int i=0,j=n-1;
            while(i<j){
                swap(nums[i++],nums[j--]);
            }
        }
        
        if(lastIndex!=-1){
            int prevIndex=lastIndex-1;
            int index=lastIndex;
            for(int i=lastIndex; i<n; i++){
                if(nums[i]>nums[prevIndex] and nums[i]<nums[lastIndex]){
                    index = i;
                }
            }
             swap(nums[index],nums[prevIndex]);
             sort(nums.begin()+lastIndex,nums.end());
        }
        
    }
};