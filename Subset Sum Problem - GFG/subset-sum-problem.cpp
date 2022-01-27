// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        
        if(sum==0) return true;
        if(n==0) return false;
        // if(arr[n-1]<=sum){
        //   return isSubsetSum(n-1,arr,sum-arr[n-1]) or isSubsetSum(n-1,arr,sum);
        // }
        // else{
        //     return isSubsetSum(n-1,arr,sum);
        // }
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<1; j++){
                dp[i][j]=true;
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
        return dp[n][sum];
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
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends