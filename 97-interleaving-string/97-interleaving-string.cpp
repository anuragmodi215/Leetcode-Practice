class Solution {
public:
    bool helper(string&s,string&t,string&word, int i, int j, int ind, vector<vector<int>>&dp){
         if(i>=0 and j>=0 and dp[i][j]!=-1) return dp[i][j];
        if(ind<0 and i<0 and j<0) return true;
        bool x = false, y=false;
        if(i>=0 and s[i]==word[ind]){
           x = helper(s,t,word,i-1,j,ind-1,dp);
        }
        if(j>=0 and t[j]==word[ind]){
            y = helper(s,t,word,i,j-1,ind-1,dp);
        }
        if(i>=0 and j>=0)  return dp[i][j] = x or y;
        return x or y;
    }
    bool isInterleave(string s, string t, string word) {
        int n = s.size();
        int m = t.size();
        int ind = word.size();
        if(n+m!=ind) return false;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s,t,word,n-1,m-1,ind-1,dp);
    }
};