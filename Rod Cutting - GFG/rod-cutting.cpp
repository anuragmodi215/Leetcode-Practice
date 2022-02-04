// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//   int solve(int price[], vector<int>length, int totalLen, int n){
//       if(n==0 or totalLen==0) return 0;
      
//       if(length[n-1]<=totalLen){
//           return max((price[n-1]+solve(price,length, totalLen-length[n-1],n)),(solve(price,length,totalLen,n-1)));
//       }
//       else{
//           return solve(price,length,totalLen,n-1);
//       }
      
//   }
  int solve(int price[], vector<int>length, int totalLen, int n){
      
      vector<vector<int>>dp(n+1,vector<int>(totalLen+1));
      for(int i=1; i<n+1; i++){
          for(int j=1; j<totalLen+1; j++){
              if(length[i-1]<=j){
                  dp[i][j]=max((price[i-1]+dp[i][j-length[i-1]]),(dp[i-1][j]));
              }
              else{
                  dp[i][j]= dp[i-1][j];
              }
          }
      }
      return dp[n][totalLen];
  }
    int cutRod(int price[], int n) {
        //code here
        vector<int> length(n);
        for(int i=0; i<n; i++) length[i]=i+1;
        return solve(price,length,n,n);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends