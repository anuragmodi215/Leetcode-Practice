// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<int,int>mp;
        long long int prefixSum=0,sum=0;
        mp[prefixSum]=1;
        int ans=0;
        for(int i=0; i<n; i++){
            prefixSum+=arr[i];
            if(mp.find(prefixSum)!=mp.end()){
                ans=ans+mp[prefixSum];
                mp[prefixSum]++;
            }
            else mp[prefixSum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends