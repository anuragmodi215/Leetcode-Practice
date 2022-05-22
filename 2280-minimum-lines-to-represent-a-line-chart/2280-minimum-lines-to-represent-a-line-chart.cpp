class Solution {
public:
    // int getSlope(int y2, int y1, int x2, int x1){
    //     return (y2-y1)/(x2-x1);
    // }
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(), stockPrices.end());
        int n = stockPrices.size();
        int lines = 1;
        if(n<2) return 0;
        if(n<3) return lines;
        
        for(int i=2; i<n; i++){
            long long int y1 = stockPrices[i-2][1];
            long long int x1 = stockPrices[i-2][0];
            
            long long int y2 = stockPrices[i-1][1];
            long long int x2 = stockPrices[i-1][0];
            
            long long int y3 = stockPrices[i][1];
            long long int x3 = stockPrices[i][0];
            
            if((y2-y1)*(x3-x2) != (y3-y2)*(x2-x1)) lines++;
        }
        return lines;
    }
};