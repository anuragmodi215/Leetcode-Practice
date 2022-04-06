class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        unordered_map<int,int>mp;
        int n=arr.size();
        long long int ans=0;
        long long int mod = 1e9+7;
        for(int i=0; i<n; i++){
            ans = (ans+(mp[target-arr[i]])%mod)%mod;
            
            for(int j=0; j<i; j++){
                mp[arr[j]+arr[i]]++;
            }
        }
        return ans;
    }
};