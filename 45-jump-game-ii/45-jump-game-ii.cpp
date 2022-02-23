class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int farthest=0;
        int currEnd=0;
        int jumps=0;
        for(int i=0; i<n; i++){
            farthest=max(farthest,i+nums[i]);
            if(currEnd==i){
                if(i<n-1){
                    jumps++;
                    currEnd=farthest;
                }
                else{
                    break;
                    //currEnd=farthest;
                }
            }
        }
        return jumps;
    }
};