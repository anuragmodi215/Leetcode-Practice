// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool allocationPossible(int a[], int n, int m, int barrier){
        int pages = 0;
        int student =1;
        
        for(int i=0; i<n; i++){
            if(a[i]>barrier) return false;
            else if(pages+a[i]>barrier){
                student++;
                pages=a[i];
            }
            else{
                pages+=a[i];
            }
        }
        if(student>m) return false;
        else return true;
    }
    int findPages(int a[], int n, int m) 
    {
        //code here
        
        int low = a[0], high = 0;
        int res = -1;
        int mid = 0;
        for(int i=0; i<n; i++) high+=a[i];
        while(low<=high){
            mid = low+(high - low)/2;
            if(allocationPossible(a,n,m,mid)){
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends