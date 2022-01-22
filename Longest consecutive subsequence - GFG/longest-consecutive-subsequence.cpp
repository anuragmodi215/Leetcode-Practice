// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_map<int,int>mp_215;
      for(int i=0; i<n; i++){
          mp_215[arr[i]]++;
      }
      int length_215,maxi_215;
      length_215=maxi_215=1;
      //cout<<maxi_215;
      for(int i=0; i<n; i++){
          int num_215=arr[i];
          if(mp_215.find(num_215-1)!=mp_215.end()) continue;
          
          else{
              while(mp_215.find(num_215+1)!=mp_215.end()){
                  num_215+=1;
                  length_215+=1;
              }
          }
          maxi_215=max(maxi_215,length_215);
          length_215=1;
      }
      return maxi_215;
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