class Solution {
public:
    int lowerBound(vector<int>&nums,int target,int n){
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return low;
    }
    int upperBound(vector<int>&nums,int target, int n){
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] == target){
                low = mid+1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ans(2,-1);
        if(n<1) return ans;
        int low = lowerBound(nums,target,n);
        int high = upperBound(nums,target,n);
        
        if(low<n and high>=0 and nums[low]==target and nums[high]==target){
            ans[0]=low;
            ans[1]=high;
        }
        return ans;
        
    }
};