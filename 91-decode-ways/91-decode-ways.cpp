class Solution {
public:
    // int helper(string &s, int n, int i, vector<int>&dp){
    //     if(i==n) return 1;
    //     if(s[i]=='0') return 0;
    //     if(i==n-1) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     int a = helper(s,n,i+1,dp);
    //     int b=0;
    //     int nums = stoi(s.substr(i,2));
    //     if(nums>0 and nums<=26){
    //         b=helper(s,n,i+2,dp);
    //     }
    //     return dp[i]=a+b;
    // }
    
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
       // return helper(s,n,0,dp);
        // int way1=0;
        // int way2=0;
        dp[0]=1;
        if(s[0]=='0')dp[1]=0;
        else dp[1]=1;
        
        for(int i=2; i<n+1; i++){
            int way1=0;
            int way2=0;
            if(s[i-1]=='0'){
                way1=0;
            }
            else{
                 way1=dp[i-1];
            }
           
            if(s[i-2]!='0'){
                int nums = stoi(s.substr(i-2,2));
                if(nums>0 and nums<=26){
                    way2 = dp[i-2];
                }

            }
            else way2=0;
            dp[i]=way1+way2;
        }
        return dp[n];
    }
};