class Solution {
public:
    int helper(int i, string&s, vector<int>&dp, int n){
        if(i>=n) return 1;
        
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int a = 0,b=0;
        if(s[i]>='1' and s[i]<='9'){
            a=helper(i+1,s,dp,n);
        }
        if(i+1<n){
            int twoEl = stoi(s.substr(i,2));
            cout<<twoEl;
            if(twoEl>=1 and twoEl<=26){
                b=helper(i+2,s,dp,n);
            }
        }
        return dp[i] = a+b;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return helper(0,s,dp,n);
    }
};