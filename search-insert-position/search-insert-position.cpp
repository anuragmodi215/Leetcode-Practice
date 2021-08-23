class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        
        while(start<=end){
            mid = (start+end)/2;
            
            if(nums[mid]==x) return mid;
            
            else if(nums[mid]>x){
                end = mid-1;
            }
            else{
                start = mid+1;
            }       
        }
        if(x>nums[mid])
         return mid+1;
        else return mid;
    }
};