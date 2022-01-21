class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int k=nums.size()/3;
        for(auto i:mp){
            if(i.second>k){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};