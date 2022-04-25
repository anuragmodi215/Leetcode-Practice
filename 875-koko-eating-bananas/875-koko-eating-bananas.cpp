class Solution {
public:
    bool helper(vector<int>& nums, int n, int h, int mid){
        int sum=0;
        
        for(int i=0; i<n; i++){
            if(nums[i]%mid==0){
                sum=sum+(nums[i]/mid);
            }
            else{
                sum=sum+(nums[i]/mid)+1;
            }
        }
        if(sum<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high=INT_MIN;
        int n = piles.size();
        for(int i=0; i<n; i++){
            high = max(high,piles[i]);
        }
        int mid = 0;
        while(low<=high){
            mid = (low+high)>>1;
            
            if(helper(piles,n,h,mid)){
                high = mid-1;
            }
            else low = mid+1;
        }
        return low;
    }
};