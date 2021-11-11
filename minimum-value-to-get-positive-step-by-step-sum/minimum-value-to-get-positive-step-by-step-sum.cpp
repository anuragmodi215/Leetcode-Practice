class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int sum=0;
        int minn=INT_MAX;
        for(auto i: nums){
            sum+=i;
            minn=min(minn,sum);
        }
        if(minn<0) return abs(minn)+1;
        return 1;
    }
};