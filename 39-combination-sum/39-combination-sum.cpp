class Solution {
public:
    vector<vector<int>>ans;
    void helper(vector<int>& candidates, int n,int target, vector<int>v){
        if(n<0 or target<0) return;
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target-candidates[n]>=0){
            v.push_back(candidates[n]);
            helper(candidates,n,target-candidates[n],v);
            v.pop_back();
        }
        
        
        helper(candidates,n-1,target,v);
     
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        helper(candidates,candidates.size()-1,target,v);
        return ans;
    }
};