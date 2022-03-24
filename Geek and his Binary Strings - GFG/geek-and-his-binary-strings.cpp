// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int helper(int n, long long int mod, vector<long long int>&dp){
	    
	    if(n<=1) return 1;
	    if(dp[n]!=-1) return dp[n];
	    long long int sum=0;
	    for(int i=0; i<n; i++){
	        long long int a = helper(i,mod,dp);
	        //a=a%mod;
	        long long int b = helper(n-i-1,mod,dp);
	        //b=b%mod;
	        sum = (sum%mod+(a*b)%mod)%mod;
	        
	    }
	    return dp[n]=sum%mod;
	}
	int prefixStrings(int N)
	{
	    // Your code goes here
	    vector<long long int>dp(N+1,-1);
	    int mod = (pow(10,9))+7;
	    return helper(N,mod,dp);
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n;
       	cin >> n;

       

        Solution ob;
        cout << ob.prefixStrings(n);
	    cout << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends