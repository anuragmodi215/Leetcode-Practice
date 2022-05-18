// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends


bool findPair(int nums[], int size, int n){
    //code
    // 
    unordered_map<int,int>mp;
    for(int i=0; i<size; i++)
        mp[nums[i]]=i;
    
    for(int i=0; i<size; i++){
        //if(i+1<n and nums[i]==nums[i+1]) continue;
        if(mp.find(nums[i]+n)!=mp.end() and mp[nums[i]+n]!=i){
            return true;
        }
    }
    return false;
}