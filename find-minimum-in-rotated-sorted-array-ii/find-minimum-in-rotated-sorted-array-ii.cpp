class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        for(auto i:nums){
            if(i<min) min=i;
        }
        return min;
    }
};