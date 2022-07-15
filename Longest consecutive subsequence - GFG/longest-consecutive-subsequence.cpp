// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
      //Your code here
      unordered_map<int,int>mp;
      int maxi=0;
      int length=0;
      for(int i=0; i<n; i++){
          mp[nums[i]]++;
      }
      for(int i=0; i<n; i++){
          length=0;
          if(mp.find(nums[i]-1)!=mp.end())continue;
          else{
              int x=nums[i];
              while(mp.find(x)!=mp.end()){
                  x++;
                  length++;
                  maxi=max(maxi,length);
              }
          }
      }
      return maxi;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends