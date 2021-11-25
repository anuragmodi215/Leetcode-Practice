class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        if(n<4) return ans;
        
        for(int i=0; i<n-3; i++){
            if(i>0 and nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int tsum=target-(nums[i]+nums[j]);
                int low=j+1,high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]==tsum){
                        vector<int>t{nums[i],nums[j],nums[low],nums[high]};
                        ans.push_back(t);
                        while(low<high and nums[low]==nums[low+1]) low++;
                        while(low<high and nums[high]==nums[high-1]) high--;
                        low++; high--;
                    }
                    else if(nums[low]+nums[high]>tsum) high--;
                    else low++;
                }
            }
        }
        return ans;
    }
};