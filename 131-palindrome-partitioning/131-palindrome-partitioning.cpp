class Solution {
public:
    bool isPal(string s, int strt, int end){
        while(strt<end){
            if(s[strt++]!=s[end--]) return false;
        }
        return true;
    }
    
    void helper(int ind, string &s, int n, vector<string>&v, vector<vector<string>>&ans){
        if(ind==n){
            ans.push_back(v);
            return;
        }
        for(int i= ind; i<n; i++){
            if(isPal(s,ind,i)){
                v.push_back(s.substr(ind,i-ind+1));
                helper(i+1,s,n,v,ans);
                v.pop_back();
            }
        }
        //return;
    }
    
    vector<vector<string>> partition(string s) {
        
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>v;
        helper(0,s,n,v,ans);
        return ans;
        
    }
};