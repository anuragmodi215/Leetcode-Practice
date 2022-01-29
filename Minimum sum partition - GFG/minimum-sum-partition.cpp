// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    vector<int> helper(int arr[], int n, long long int sum){
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<1; j++){
                dp[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j-arr[i-1]] or dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        vector<int>v;
        for(int i=n; i<n+1; i++){
            for(int j=0; j<=sum/2; j++){
                if(dp[i][j]) v.push_back(j);
            }
        }
        return v;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    long long int sum=0;
	    for(int i=0; i<n; i++) sum+=arr[i];
	    vector<int> v=helper(arr,n,sum);
	    long long int mini=INT_MAX;
	    
	    for(int i=0; i<v.size(); i++){
	        mini=min(mini,sum-2*(v[i]));
	    }
	    return mini;
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends