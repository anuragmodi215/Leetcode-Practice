class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastIndex=-1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i-1]<nums[i]){
                lastIndex=i;
            }
        }
        if(lastIndex==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        else{
            int index=lastIndex;
            int prevIndex=lastIndex-1;
            for(int i=lastIndex; i<n; i++){
                if(nums[i]>nums[prevIndex] and nums[i]<nums[lastIndex]){
                    index = i;
                }
            }
            swap(nums[index],nums[prevIndex]);
            sort(nums.begin()+prevIndex+1,nums.end());
        }
        return;
    }
};