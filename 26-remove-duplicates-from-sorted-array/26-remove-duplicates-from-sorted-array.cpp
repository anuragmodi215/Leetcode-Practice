class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int slow = 0;
        int fast = slow+1;
        int n = nums.size();
        for(; fast<n; fast++){
            if(nums[slow]==nums[fast]){
                nums[slow] = nums[fast];
            }
            else{
                slow++;
                nums[slow] = nums[fast];
            }
        }
            
        return slow+1;
    }
};