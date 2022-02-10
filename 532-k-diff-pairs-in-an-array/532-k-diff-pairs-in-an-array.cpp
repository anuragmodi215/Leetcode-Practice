class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(i>0 and nums[i-1]==nums[i]) continue;
            else{
                int el = nums[i]+k;
                int strt=i+1;
                if(binary_search(nums.begin()+strt,nums.end(),el)) 
                    cnt++;
            }
        }
        return cnt;
    }
};