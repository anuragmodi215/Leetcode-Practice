// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>nums, int sum){
        // code here 
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;
       for(int i=1; i<n; i++){
           for(int target=1; target<=sum; target++){
               int notTake = dp[i-1][target];
               int take=0;
               if(nums[i]<=target){
                   take = dp[i-1][target-nums[i]];
               }
               dp[i][target] = notTake or take;
           }
       }
       return dp[n-1][sum];
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