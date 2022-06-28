class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalCost=0;
        int currCost=0;
        int startIndex=0;
        for(int i=0; i<n; i++){
            totalCost = totalCost+(gas[i]-cost[i]);
            currCost = currCost+(gas[i]-cost[i]);
            if(currCost<0){
                currCost=0;
                startIndex = i+1;
            }
        }
        if(totalCost>=0) return startIndex;
        return -1;
    }
};