class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto &i:nums){
            mp[i]++;
        }
        int cnt=0;
        for(auto &i:mp){
            if(k==0){
                if(i.second>=2) cnt++;
            }
            else{
                if(mp.find(i.first-k)!=mp.end()) cnt++;
            }
        }
        return cnt;
    }
};