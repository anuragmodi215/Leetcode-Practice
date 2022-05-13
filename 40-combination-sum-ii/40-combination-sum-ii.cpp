class Solution {
public:
    
    void helper(int ind, int target,int n, vector<int>&nums, vector<int>v, vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(i!=ind and nums[i]==nums[i-1])continue;
            
            if(target-nums[i]>=0){
                v.push_back(nums[i]);
                helper(i+1, target-nums[i],n, nums, v, ans);
                v.pop_back();
            }
            else return;
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>v;
        helper(0,target,n,candidates,v,ans);
        return ans;
    }
};