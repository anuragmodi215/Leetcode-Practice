class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int sum=INT_MIN;
       while(i<j){
           int maxi=nums[i++]+nums[j--];
           sum = max(sum,maxi);
       }
        return sum;
    }
};