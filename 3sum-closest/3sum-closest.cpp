class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int min_sum=nums[0]+nums[1]+nums[2];
        for(int i=0; i<n; i++){
            if(i>0 and nums[i-1]==nums[i]) continue;
            else{
                int left=i+1;
                int right=n-1;
                while(left<right){
                    int sum = nums[i]+nums[left]+nums[right];
                    if(sum==target) return sum;
                    if(abs(sum-target)<abs(min_sum-target))
                    min_sum=sum;
                    if(sum>target) right--;
                    else if(sum<target)left++;
                }
            }
        }
        return min_sum;
    }
};