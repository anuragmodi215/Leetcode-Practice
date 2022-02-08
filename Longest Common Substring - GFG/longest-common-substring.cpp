// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
//     int ans=INT_MIN;
// int helper(string &s, string &str, int n, int m,vector<vector<int>>&dp){
//         if(n==0 or m==0) return 0;
//         if(dp[n][m]!=-1) return dp[n][m];
        
//         if(s[n-1]==str[m-1]){
//             ans=max(ans,1+helper(s,str,n-1,m-1,dp));
//             return dp[n][m]=ans;
//         }
//         else{
//             dp[n][m]=0;
//             //helper(s,str,n-1,m-1,dp);
//             return 0;
//             //return dp[n][m];
//         }
//     }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int ans=0;
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0; i<n+1; i++){
            dp[i][0]=0;
        }
        for(int j=0; j<m+1; j++){
            dp[0][j]=0;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        //helper(s1,s2,n,m,dp);
        return ans;
    }
};



















// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends