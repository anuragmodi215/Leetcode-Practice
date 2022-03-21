class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i-1]!=nums[i])
                v.push_back(nums[i]);
        }
        int cnt=0;
        n=v.size();
        for(int i=1; i<n-1; i++){
            if(v[i]<v[i-1] and v[i]<v[i+1] or v[i]>v[i-1] and v[i]>v[i+1]) cnt++;
        }
        return cnt;
    }
};