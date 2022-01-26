class Solution {
public:
    void helper(vector<int>& candidates,int target, vector<vector<int>>&ans,vector<int>v,int ind){
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        for(int i=ind; i<candidates.size(); i++){
            if(i>ind and candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            v.push_back(candidates[i]);
            helper(candidates,target-candidates[i],ans,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        helper(candidates,target,ans,v,0);
        return ans;
    }
};