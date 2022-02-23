class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        
        for(int reach=0; i<=reach and i<n; i++){
            reach=max(reach,nums[i]+i);
        }
        
        if(i==n) return true;
        else return false;
    }
};