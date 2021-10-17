class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int strt=0,end=n-1,mid,prev,next;
        
        while(strt<=end){
            mid=strt+(end-strt)/2;
            prev=abs((mid-1)%n);
            next=abs((mid+1)%n);
            
            if(nums[mid]<nums[prev] and nums[mid]<nums[next]) return nums[mid];
            else if(nums[mid]>nums[end])strt=mid+1;
            else end=mid-1;
        }
        return nums[mid];
    }
};