class Solution {
public:
    bool helper(string &s, int pos, unordered_set<string> &set, int n, vector<int>&dp){
        if(pos>=n) return true;
        if(dp[pos]!=-1) return dp[pos];
        string temp;
        for(int i=pos; i<n; i++){
            temp+=s[i];
            cout<<temp<<endl;
            if(set.find(temp)!=set.end()){
                 if(helper(s,i+1,set,n,dp)) return dp[i]= true;
            }
        }
        return dp[pos] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        int n=s.size();
        vector<int>dp(n,-1);
        for(int i=0; i<wordDict.size(); i++){
            set.insert(wordDict[i]);
        }
        
        return helper(s, 0, set, s.size(),dp);
    }
};