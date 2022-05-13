class Solution {
public:
    
    void helper(int ind, int n,vector<int>&nums, vector<vector<int>>&ans){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind; i<n; i++){
            swap(nums[i],nums[ind]);
            helper(ind+1, n, nums,ans);
            swap(nums[i],nums[ind]);
            
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        //vector<int>v;
        int n = nums.size();
        helper(0,n,nums,ans);
        return ans;
    }
};