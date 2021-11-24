class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        for(int i=0; i<n-1; i++){
            if(i>0 and nums[i-1]==nums[i]) continue;
            else{
                int strt=i;
                int end=n-1;
                if(binary_search(nums.begin()+strt+1,nums.end(),k+nums[i])){
                    cnt++;
                }
                
               
            
            }
        }
        return cnt;
    }
};