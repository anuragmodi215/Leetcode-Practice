class Solution {
public:
    vector<vector<int>> ans;
    void per(vector<int>& nums, int ind){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind; i<nums.size(); i++){
            swap(nums[i],nums[ind]);
            per(nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        per(nums,0);
        return ans;
    }
};