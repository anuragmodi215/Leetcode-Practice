class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        int maxSum=0;
        int sum=0;
        unordered_map<int,int>mp;
        while(j<n){
            if(mp.find(nums[j])==mp.end()){
                mp[nums[j]]++;
                sum+=nums[j];
                maxSum = max(sum,maxSum);
                j++;
            }
            else{
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
        }
        return maxSum;
    }
};