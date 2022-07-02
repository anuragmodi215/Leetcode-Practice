// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int nums[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int>mp;
        int ps = 0;
        mp[ps]=-1;
        int len=0;
        for(int i=0; i<n; i++){
            ps+=nums[i];
            if(mp.find(ps-k)!=mp.end()){
                len=max(len,i-mp[ps-k]);
            }
            if(mp.find(ps)==mp.end()){
                mp[ps]=i;
            }
        }
        return len;
    } 

};

// { Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends