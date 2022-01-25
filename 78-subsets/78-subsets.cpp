class Solution {
public:
     vector<vector<int>> ans;
    void helper(vector<int>& nums,int ind, vector<int> v){
        int n =nums.size();
        if(ind==n){
            ans.push_back(v);
            return;
        }
        //for(int i=ind; i<n; i++){
            helper(nums,ind+1,v);
            v.push_back(nums[ind]);
            helper(nums,ind+1,v);
        //}
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        helper(nums,0,v);
        return ans;
    }
};