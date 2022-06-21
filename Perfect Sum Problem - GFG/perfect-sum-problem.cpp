// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	long long int mod = 1000000007;
	int helper(int nums[],int index, int target,vector<vector<int>>&dp){
	    
	    if(index==0){
	        if(target==0 and nums[0]==0) return 2;
	        if(target==0 or nums[0] == target) return 1;
	        else return 0;
	    }
	    //if(target==0) return 1;
	    if(dp[index][target]!=-1) return dp[index][target];
	    int notTake = helper(nums,index-1,target,dp);
	    int take = 0;
	    if(nums[index]<=target){
	        take = helper(nums,index-1,target-nums[index],dp);
	    }
	    return dp[index][target] = (take + notTake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(arr,n-1,sum,dp);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends