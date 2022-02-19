class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int>set;
        for(auto &i:nums){
            set.insert(i);
        }
        
        int min_dev=(*set.rbegin()-*set.begin());
        int val = *set.begin();
        while(val%2==1){
            val*=2;
            set.erase(*set.begin());
            set.insert(val);
            val = *set.begin();
            min_dev = min(min_dev, (*set.rbegin()-*set.begin()));
        }
        val=*set.rbegin();
        while(val%2==0){
            val/=2;
            set.erase(*set.rbegin());
            set.insert(val);
            val = *set.rbegin();
            min_dev = min(min_dev,(*set.rbegin()-*set.begin()));
        }
        
        return min_dev;
    }
};