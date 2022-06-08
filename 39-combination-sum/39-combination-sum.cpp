class Solution {
public:
    void helper(int ind,vector<int>& candidates,vector<int>v,int n, int target,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=ind; i<n; i++){
            if(target-candidates[i]>=0){
                v.push_back(candidates[i]);
                helper(i,candidates,v,n,target-candidates[i],ans);
                v.pop_back();
            }
            else{
                return;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int>>ans;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,v,n,target,ans);
        return ans;
    }
};