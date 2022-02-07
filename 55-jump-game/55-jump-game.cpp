class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach=0;
        int i;
        for(i=0; i<n and i<=reach; i++){
            reach=max(reach,nums[i]+i);
        }
        
        if(i==n) return true;
        else return false;
    }
};