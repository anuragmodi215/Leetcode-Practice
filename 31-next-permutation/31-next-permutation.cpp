class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int lastInd=-1;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                lastInd = i;
            }
        }
        if(lastInd==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            int prevInd=lastInd-1;
            int index = lastInd;
            
            for(int i=lastInd; i<n; i++){
                if(nums[i]>nums[prevInd] and nums[i]<nums[lastInd]){
                    index = i;
                }
            }
            swap(nums[index],nums[prevInd]);
            sort(nums.begin()+lastInd,nums.end());
        }
    }
};