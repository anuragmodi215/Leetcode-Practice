// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int k) {
        // Your code goes here
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            int a = nums[i];
            for(int j=i+1; j<n; j++){
                if(j>i+1 and nums[j]==nums[j-1]){
                    continue;
                }
                int b = nums[j];
                
                int target = k-a-b;
                
                int low = j+1,high = n-1;
                
                while(low<high){
                    int sum = nums[low]+nums[high];
                    if(sum<target) low++;
                    else if(sum>target) high--;
                    else if(sum==target){
                        vector<int>temp{a,b,nums[low],nums[high]};
                        ans.push_back(temp);
                        while(low<high and nums[low]==nums[low+1])low++;
                        while(low<high and nums[high]==nums[high-1])high--;
                        low++;high--;
                    }
                }
            }
        }
        return ans;
    }
};















// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends