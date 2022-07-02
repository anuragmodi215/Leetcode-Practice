class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ps=0;
        mp[ps]=1;
        int ans=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            ps+=nums[i];
            if(mp.find(ps-k)!=mp.end()){
                ans = ans+mp[ps-k];
            }
            mp[ps]++;     
        }
        return ans;
    }
};