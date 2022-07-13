// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int nums[], int n, int k) {
        // code here
        sort(nums,nums+n);
        int ans = nums[n-1]-nums[0];
        int mini,maxi;
        for(int i=1; i<n; i++){
            if(nums[i]-k<0 )continue;
            maxi = max(nums[i-1]+k,nums[n-1]-k);
            mini = min(nums[i]-k,nums[0]+k);
            ans = min(ans,maxi-mini);
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
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends