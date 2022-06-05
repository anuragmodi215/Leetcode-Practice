class Solution {
public:
    bool isPossible(vector<int>&nums, int mid, int m, int n){
        int split=1;
        int sums=0;
        for(int i=0; i<n; i++){
            if(nums[i]>mid) return false;
            else if(sums+nums[i]>mid){
                split++;
                sums = nums[i];
            }
            else{
                sums+=nums[i];
            }
        }
        if(split>m) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int low = 0;
        int high = 0;
        int n = nums.size();
        for(auto i:nums){
            high+=i;
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(nums,mid,m,n)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};