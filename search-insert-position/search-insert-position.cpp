class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int strt=0,end=nums.size()-1;
        int prev=0;
        while(strt<=end){
            int mid=strt+(end-strt)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target){
                prev=mid+1;
                strt=mid+1;
            }
            else end=mid-1;
        }
        return prev;
    }
};