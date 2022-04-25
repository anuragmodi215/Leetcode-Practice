class Solution {
public:
    int helper(vector<int>& nums, int n, int m, int mid){
        int cnt = 1;
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum>mid){
                sum=nums[i];
                cnt++;
            }
        }
        if(cnt>m) return 0;
        else return 1;
    }
    int splitArray(vector<int>& nums, int m){
        int high = 0;
        int low = INT_MIN; 
        int n = nums.size();
        for(int i=0; i<n; i++){
            low = max(nums[i],low);
            high+=nums[i];
        }
        
        while(low<=high){
            int mid = (low+high)>>1;
            if(helper(nums,n,m,mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};