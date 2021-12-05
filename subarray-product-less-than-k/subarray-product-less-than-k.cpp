class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int cnt=0;
        int n=nums.size(),i=0,j=0,product=1;
        while(j<n){
            product*=nums[j];
            while(i<=j and product>=k){
                product/=nums[i++];
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
};