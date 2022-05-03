// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], long long temp[], int low, int mid, int high){
        int i=low;
        int j=mid; 
        int k=low;
        long long int inv = 0;
        while(i<mid and j<=high){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                inv = inv + mid-i;
            }
        }
        
        while(i<mid){
            temp[k++] = arr[i++];
        }
        while(j<=high){
            temp[k++] = arr[j++];
        }
        for(int i=low; i<=high; i++){
            arr[i] = temp[i];
        }
        return inv;
    }
    long long int mergeSort(long long arr[], long long temp[], int low, int high){
        long long int inv = 0;
        if(low<high){
            int mid = low+(high-low)/2;
            inv = inv + mergeSort(arr,temp, low, mid);
            inv = inv + mergeSort(arr, temp, mid+1, high);
            inv = inv + merge(arr,temp,low, mid+1, high);
        }
        return inv;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long temp[n];
        return mergeSort(arr,temp,0,n-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends