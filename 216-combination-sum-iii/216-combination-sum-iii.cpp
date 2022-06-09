class Solution {
public:
    void helper(int index, int k, int n, vector<int>output,vector<vector<int>>&ans, int sum){
        if(output.size()>=k and sum<n){
            return;
        }
        else if(output.size()==k and sum==n){
            ans.push_back(output);
            return;
        }
        for(int i= index; i<=9; i++){
            if(sum+i<=n){
                output.push_back(i);
                helper(i+1,k,n,output,ans,sum+i);
                output.pop_back();
            }
            else return;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>output;
        helper(1,k,n,output,ans,0);
        return ans;
    }
};