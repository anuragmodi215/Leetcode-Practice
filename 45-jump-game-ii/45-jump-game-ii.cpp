class Solution {
public:
    int jump(vector<int>& nums) {
        int pos=0;
        int jump=0;
        int des=0;
        int i;
        int n = nums.size();
        for(i=0; i<n-1; i++){
            des = max(des,i+nums[i]);
            if(i==pos){
                pos = des;
                jump++;
            }
        }
        return jump;
    }
};