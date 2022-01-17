// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int maxi=0;
	    unordered_map<long long int,int>mp;
	    long long int ps=0;
	    mp[ps]=-1;
	    for(int i=0; i<n; i++){
	        ps+=arr[i];
	        ps=((ps%k)+k)%k;
	        if(mp.find(ps)!=mp.end()){
	            maxi=max(maxi,i-mp[ps]);
	        }
	        else mp[ps]=i;
	    }
	    return maxi;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends