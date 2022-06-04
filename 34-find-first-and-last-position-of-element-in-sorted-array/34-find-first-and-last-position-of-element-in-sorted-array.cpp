class Solution {
public:
    
    int firstPosition(vector<int>&nums,int target, int n){
        int low = 0, high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
        }
       if(low>=0 and low<n and nums[low]==target){
           return low;
       }
        else return -1;
    }
    
    int lastPosition(vector<int>&nums,int target, int n){
        int low = 0, high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
        }
        
        if(high>=0 and high<n and nums[high]==target){
            return high;
        }
        else return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return {-1,-1};
        int lowerIndex = firstPosition(nums,target,n);
        int upperIndex =-1;
        if(lowerIndex>-1){
              upperIndex = lastPosition(nums,target,n);
        }
      return {lowerIndex,upperIndex};
        
    }
};