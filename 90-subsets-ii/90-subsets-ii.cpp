class Solution {
public:
    void helper(int ind, int n, vector<int>v, vector<vector<int>>&ans,vector<int>& nums){
        ans.push_back(v);
        
        for(int i=ind; i<n; i++){
            if(i!=ind and nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            helper(i+1, n, v, ans, nums);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        helper(0,n,v,ans,nums);
        return ans;
    }
};