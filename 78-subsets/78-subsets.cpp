class Solution {
public:
    void helper(vector<int>& nums,int n, vector<int>v,vector<vector<int>>&ans){
        if(n==0){
            ans.push_back(v);
            return;
        }
        helper(nums,n-1,v,ans);
        v.push_back(nums[n-1]);
        helper(nums,n-1,v,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int n = nums.size();
        helper(nums,n,v,ans);
        return ans;
    }
};