class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int ps=0;
        int count=0;
        mp[ps]=1;
        for(int i=0; i<n; i++){
            ps+=nums[i];
            if(mp.find(ps-k)!=mp.end()){
                count+=mp[ps-k];
            }
            mp[ps]++;
        }
        return count;
    }
};