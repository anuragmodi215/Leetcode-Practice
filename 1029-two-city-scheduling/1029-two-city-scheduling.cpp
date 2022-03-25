class Solution {
public:

    int twoCitySchedCost(vector<vector<int>>& cost) {
        sort(cost.begin(),cost.end(),[](const vector<int>&a, const vector<int>&b){
            return (a[0]-a[1]) < (b[0]-b[1]);  
        });
        
        int n = cost.size();
        int exp=0;
        
        for(int i=0; i<n/2; i++){
            exp+=cost[i][0];
        }
        for(int i=n/2; i<n; i++){
            exp+=cost[i][1];
        }
        return exp;
    }
};