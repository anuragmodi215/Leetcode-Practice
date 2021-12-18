class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int strt=0,end=n-1;
        while(strt<=end){
           int mid=strt+(end-strt)/2;
           if(nums[abs((mid+1)%n)]>nums[mid] and nums[abs((mid-1)%n)]>nums[mid]){
               return nums[mid];
           }
            else if(nums[mid]>nums[end]){
                strt=mid+1;
            }
            else end =mid-1;
        }
        return nums[0];
    }
};

















