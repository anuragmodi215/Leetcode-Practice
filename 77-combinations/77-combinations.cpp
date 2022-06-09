class Solution {
public:
    void helper(int input, vector<int>output, int n, int k, vector<vector<int>>&ans){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }
        for(int i=input; i<=n; i++){
            output.push_back(i);
            helper(i+1,output,n,k,ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>output;
        helper(1,output,n,k,ans);
        return ans;
    }
};