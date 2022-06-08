class Solution {
public:
    bool canPermute(int start, int curr, vector<int>&nums){
        for(int i=start; i<curr; i++){
            if(nums[i]==nums[curr]) return false;
        }
        return true;
    }
    void helper(int index,int n, vector<int>nums, vector<vector<int>>&ans){
        if(index==n){
            ans.push_back(nums);
            return;
        }
        for(int i = index; i<n; i++){
            if(i!=index and !canPermute(index,i,nums)) continue;
            swap(nums[i],nums[index]);
            helper(index+1,n,nums,ans);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        helper(0,nums.size(),nums,ans);
        return ans;
    }
};