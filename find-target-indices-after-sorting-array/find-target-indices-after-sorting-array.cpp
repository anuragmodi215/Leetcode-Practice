class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto strt=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        auto end=upper_bound(nums.begin(),nums.end(),target) -nums.begin();
        
        vector<int>ans;
        for(auto i=strt; i<end; i++) ans.push_back(i);
        return ans;
    }
};