class Solution {
public:
    vector<vector<int>>ans;
    void helper(int strt, int k, int n, vector<int>v){
        if(n==0 and v.size()==k){
            ans.push_back(v);
            return;
        }
        if(n<=0 or v.size()>=k)return;
        
        for(int i=strt; i<=9; i++){
            v.push_back(i);
            helper(i+1, k, n-i,v);
            v.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        helper(1,k,n,v);
        return ans;
    }
};