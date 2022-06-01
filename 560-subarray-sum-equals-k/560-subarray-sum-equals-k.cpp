class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ps = 0;
        mp[ps]=1;
        int cnt=0;
        int n = nums.size();
        for(int i=0;i<n; i++){
            ps+=nums[i];
            int find = ps-k;
            if(mp.find(find)!=mp.end()){
                cnt+=mp[find];
            }
            mp[ps]++;
        }
        return cnt;
    }
};