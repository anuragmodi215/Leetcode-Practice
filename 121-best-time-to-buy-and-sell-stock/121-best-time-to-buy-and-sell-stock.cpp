class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int buy=INT_MAX;
        int n = prices.size();
        
        for(int i=0; i<n; i++){
            buy = min(prices[i],buy);
            profit = max(profit, prices[i]-buy);
        }
        return profit;
    }
};