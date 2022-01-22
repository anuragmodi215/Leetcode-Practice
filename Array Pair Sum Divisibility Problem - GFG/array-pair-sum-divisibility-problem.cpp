// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>mp_215;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mp_215[nums[i]%k]++;
        }
        
        for(auto i:mp_215){
            if(i.first==0){
                if(i.second%2==1) return false;
            }
            else if(mp_215.find(k-i.first)==mp_215.end()){
                return false;
            }
            else{
                if(mp_215[k-i.first]!=mp_215[i.first]) return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends