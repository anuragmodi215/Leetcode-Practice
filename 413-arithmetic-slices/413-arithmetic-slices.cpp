class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        //vector<int>dp(n);
        int cnt=0;
        int ans=0;
        for(int i=1; i<n-1; i++){
            if((nums[i-1]-nums[i]) == (nums[i]-nums[i+1])){
                cnt++;
            }
            else{
                cnt=0;
            }
            ans+=cnt;
        }
        return ans;
    }
};