// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int helper(int price[], int index, int length, vector<vector<int>>&dp){
        if(index==0){
            return length*price[0];
        }
        if(dp[index][length]!=-1) return dp[index][length];
        int notTake = helper(price,index-1,length,dp);
        int take = INT_MIN;
        int rodLength = index+1;
        if(rodLength<=length){
            take = price[index]+helper(price,index,length-rodLength,dp);
        }
        return dp[index][length] = max(take,notTake);
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(price,n-1,n,dp);
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