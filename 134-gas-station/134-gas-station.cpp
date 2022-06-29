class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int currCost=0;
        int totalCost=0;
        int n = gas.size();
        int index=0;
        for(int i=0; i<n; i++){
            currCost = currCost+gas[i]-cost[i];
            totalCost = totalCost+gas[i]-cost[i];
            if(currCost<0){
                currCost=0;
                index=i+1;
            }
        }
        if(totalCost>=0) return index;
        return -1;
    }
};