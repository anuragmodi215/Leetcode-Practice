class Solution {
public:
    
    int helper(string &s, int n, int strt, int cnt,vector<vector<int>>&dp){
        if(cnt<0) return 0;
        if(strt==n){
           if(cnt==0) return 1;
           else return 0;
       } 
       if(dp[strt][cnt]!=-1) return dp[strt][cnt];
        int y = cnt;
        int res;
        if(s[strt]=='('){
            res = helper(s,n,strt+1,cnt+1, dp);
        }
        else if(s[strt]==')'){
            if(cnt<=0) return 0;
            res = helper(s,n,strt+1,cnt-1,dp);
        }
        else{
            res = helper(s,n,strt+1,cnt+1, dp) or helper(s,n,strt+1,cnt-1, dp) or helper(s,n,strt+1,cnt, dp);;
        }
        return dp[strt][y] = res;
    }
    bool checkValidString(string s) {
        
        int n=s.size();
        int cnt=0;
        //  for(int i=0; i<n; i++){
        //      if(s[i]=='*') cnt++;
        //  }
        // if(cnt==n) return true;
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int x = helper(s,n,0,0,dp);
        if(x==1) return true;
        else return false;
    }
};