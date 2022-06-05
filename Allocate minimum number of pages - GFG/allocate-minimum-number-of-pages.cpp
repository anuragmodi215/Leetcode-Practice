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
    bool isPossible(int a[], int mid, int n, int m){
        int student = 1;
        int pages=0;
        for(int i=0; i<n; i++){
            if(a[i]>mid) return false;
            else if(pages+a[i]>mid){
                student++;
                pages=a[i];
            }
            else{
                pages+=a[i];
            }
        }
        if(student>m) return false;
        return true;
    }
    int findPages(int a[], int n, int m) 
    {
        //code here
        int low = 0;
        int high = 0;
        for(int i=0; i<n; i++){
            high+=a[i];
        }
        
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(a,mid,n,m)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
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