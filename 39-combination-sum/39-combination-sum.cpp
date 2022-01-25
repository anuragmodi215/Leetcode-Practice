class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& candidates,int target,vector<int>v,int i){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(i>=candidates.size()) return;
     
            if(target-candidates[i]>=0){
                v.push_back(candidates[i]);
                helper(candidates,target-candidates[i],v,i);
                v.pop_back();
            }
                          
                helper(candidates,target,v,i+1);
     
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        helper(candidates,target,v,0);
        return ans;
    }
};