class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(freq.find(target-nums[i])!=freq.end()){
                return {freq[target-nums[i]],i};
            }
            freq[nums[i]]=i;
        }
        return {};
    }
};