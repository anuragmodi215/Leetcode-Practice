class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int strt=0,end=nums.size()-1;
        vector<int>ans;
        int res=-1;
        while(strt<=end){
            int mid=strt+(end-strt)/2;
            if(nums[mid]==target){
                res=mid;
                end=mid-1;
            }
            else if(nums[mid]<target) strt=mid+1;
            else end=mid-1;
        }
        
        ans.push_back(res);
        
        strt=0,end=nums.size()-1,res=-1;
        
        while(strt<=end){
            int mid=strt+(end-strt)/2;
            if(nums[mid]==target){
                res=mid;
                strt=mid+1;
            }
            else if(nums[mid]<target) strt=mid+1;
            else end=mid-1;
        }
       
        ans.push_back(res);
        return ans;
    }
};













