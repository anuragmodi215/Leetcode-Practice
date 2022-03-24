// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool subset(vector<int>arr,int n,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)
        return dp[n][sum]=1;
        if(n==0)
        return dp[n][sum]=0;
        
        
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        
        if(arr[n-1]<=sum)
        return dp[n][sum]=subset(arr,n-1,sum-arr[n-1],dp)||subset(arr,n-1,sum,dp);
        else
        return dp[n][sum]=subset(arr,n-1,sum,dp);
        return 0;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(101,vector<int>(10001,-1));
        return subset(arr,arr.size(),sum,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends