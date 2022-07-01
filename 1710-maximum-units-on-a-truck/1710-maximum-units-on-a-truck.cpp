class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {
        sort(nums.begin(),nums.end(),cmp);
        int n = nums.size()-1;
        int ans = 0;
        for(int i=n; i>=0; i--){
            if(truckSize>=nums[i][0]){
                ans+=nums[i][0]*nums[i][1];
                truckSize=truckSize-nums[i][0];
            }
            else{
                ans+=truckSize*nums[i][1];
                break;
            }
        }
        return ans;
    }
};