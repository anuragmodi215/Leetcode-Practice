class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        long long i=2;
        vector<long long>v;
        if(finalSum % 2==1) return v;
        
        while(i<=finalSum){
            v.push_back(i);
            finalSum-=i;
            i+=2;
        }
        v[v.size()-1] = v[v.size()-1]+(finalSum);
        return v;
        
    }
};