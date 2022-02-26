class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int strt=0;
        int end=0;
        int n=prices.size();
        int legProfit=0;
        int MTM=0;
        bool increment = 0;
        for(int i=1; i<n; i++){
            if(prices[i]<=prices[i-1])
            {
                strt=i;
                //i++;
            }
            else if(prices[i]>prices[i-1])
            {
                while(i<n and prices[i]>prices[i-1]) 
                {
                    legProfit=prices[i]-prices[strt];
                     i++;
                    increment=1;
                }
                
               // cout<<i;
              
                //legProfit=prices[i]-prices[strt];
                MTM+=legProfit;
                cout<<legProfit;
                if(increment) i--;
                increment=0;
            }
            
        }
        return MTM;
    }
};