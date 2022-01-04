// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int len=0;
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0; i<n; i++){
            sum=sum+a[i];
            if(sum==0){
                len=max(i+1,len);
            }
            else if(mp.find(sum)!=mp.end()){
                len=max(i-mp[sum],len);
            }
            else{
                mp[sum]=i;
            }
        }
        return len;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends