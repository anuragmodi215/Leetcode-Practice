class Solution {
public:
    bool helper(vector<int>& nums, int n, int mid, int threshold){
        int sum=0;
        for(int i=0; i<n; i++){
            if(nums[i]<mid) sum++;
            else if(nums[i]%mid==0){
                sum=sum+(nums[i]/mid);
            }
            else if(nums[i]>mid){
                sum = sum + (nums[i]/mid)+1;
            }
        }
        
        if(sum<=threshold) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high=INT_MIN;
        for(int i=0; i<n; i++){
            high = max(high,nums[i]);
        }
        int mid=0;
        int res = 0;
        //cout<<high<<endl;
        while(low<=high){
            mid = (low+high)>>1;
            if(helper(nums,n,mid,threshold)){
                res = mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};