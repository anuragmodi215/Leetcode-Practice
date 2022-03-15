class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long one=LONG_MIN,two=LONG_MIN,three=LONG_MIN;
        int n=nums.size();
        for(auto &i:nums){
            if(one==i or two ==i or three ==i) continue;
            else{
                if(i>one){
                    three=two;
                    two=one;
                    one=i;
                }
                else if(i>two){
                    three = two;
                    two = i;
                }
                else if(i>three){
                    three=i;
                }
            }
        }
        if(three==LONG_MIN) return one;
        return three;
    }
};