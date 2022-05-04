class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        if(n<4) return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if(i>0 and nums[i]==nums[i-1])continue;
            // a+b+c+d==target
            // c+d == target-a-b;
            for(int j=i+1; j<n; j++){
                if(j>i+1 and nums[j]==nums[j-1]) continue;
                int newTarget = target-nums[i]-nums[j];
                int right=n-1,left=j+1;
                while(left<right){
                    int sum = nums[left]+nums[right];
                    
                    if(sum<newTarget) left++;
                    else if(sum>newTarget) right--;
                    else if(sum==newTarget){
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left<right and nums[left]==nums[left+1]){
                            left++;
                        }
                        left++;
                        while(right>left and nums[right]==nums[right-1]){
                            right--;
                        }
                        right--;
                    }
                }
            }
        }
        
        return ans;
    }
};