class Solution {
public:
    int helper(string s, int n, int i,vector<int>&dp){
        if(s[i]=='0') return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        
        int x = helper(s,n,i+1,dp);
        int y=0;
        if(i+1<n){
            int nums = stoi(s.substr(i,2));
            if(nums>0 and nums<=26){
                y=helper(s,n,i+2,dp); 
        }            
        }

        
        return dp[i] = x+y;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return helper(s,n,0,dp);
    }
};