// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int nums[], int n, int k) {
        // code here
        unordered_map<int,int>mp;
        int cnt=0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(mp.find(k-nums[i])!=mp.end()){
                ans +=mp[k-nums[i]];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends