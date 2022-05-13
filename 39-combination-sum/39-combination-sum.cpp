class Solution {
public:
    
    void helper(int ind, int target, int n, vector<int>v, vector<vector<int>>&ans, vector<int>&nums){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<n; i++){
            if(target-nums[i]>=0){
                v.push_back(nums[i]);
                helper(i,target-nums[i],n,v,ans,nums);
                v.pop_back();
            }
            else{
                return;
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        int n = candidates.size();
        helper(0,target,n,v,ans,candidates);
        return ans;
    }
};