// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
// int helper(int n, int W, int val[], int wt[]){
//     if(W<=0 or n<=0) return 0;
    
//     if(wt[n]<=W){
//             return max((helper(n,W-wt[n],val,wt)+val[n]),(helper(n-1,W,val,wt)));
//         }
//         else{
//             return helper(n-1,W,val,wt);
//         }
// }
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp((n+1),vector<int>(W+1));
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<W+1; j++){
                if(wt[i-1]<=j)
                dp[i][j]=max((dp[i][j-wt[i-1]]+val[i-1]),(dp[i-1][j]));
                
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][W];
        //return helper(n-1,W,val,wt);
        //if(n<0) return 0;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends