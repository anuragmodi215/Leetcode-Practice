class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastIndex = -1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                lastIndex=i;
            }
        }
        if(lastIndex==-1) reverse(nums.begin(),nums.end());
        else{
            int prevIndex = lastIndex-1;
            int index = lastIndex;
            //cout<<prevIndex<<" "<<index;
            for(int i=lastIndex; i<n; i++){
                if(nums[i]>nums[prevIndex] and nums[i]<nums[lastIndex]){
                    index = i;
                }
            }
            swap(nums[index],nums[prevIndex]);
            //for(auto i:nums)cout<<i<<" ";
            sort(nums.begin()+prevIndex+1,nums.end());
        }
    }
};