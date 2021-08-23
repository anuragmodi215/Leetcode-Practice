class Solution {
public:
    
    void reverse(vector<int>&nums,int i,int j){
        while(i<j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j]=temp;
            i++; j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums,0,nums.size()-1-k);
        reverse(nums,nums.size()-k, nums.size()-1);
        reverse(nums,0,nums.size()-1);
    }
};