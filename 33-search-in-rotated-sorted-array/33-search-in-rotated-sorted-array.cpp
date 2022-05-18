class Solution {
public:
    int findPivot(vector<int>&nums,int n){
        int low = 0,high = n-1,prev,next;
        int mid;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            int prev = (abs(mid-1))%n;
            int next = (abs(mid+1))%n;
            if(nums[mid]<nums[prev] and nums[mid]<nums[next]){
                return mid;
            }
            else if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return mid;
    }
    int binarySearch(vector<int>&nums, int target,int low , int high){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums,n);
        int index = -1;
        
        index = binarySearch(nums,target,0,pivot-1);
        
        if(index==-1){
            index = binarySearch(nums,target,pivot,n-1);
        }
        return index;
    }
};