class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> v;
        stack<int> st;
        int n = prices.size();
        for(int i=n-1; i>=0; i--){
            if(st.size()==0) v.push_back(prices[i]);
            
            else if(st.size() > 0 and st.top()<=prices[i]){
                v.push_back((prices[i]-st.top()));
            }
            else{
                while(st.size()>0 and st.top()>prices[i]) st.pop();
                if(st.size() == 0) v.push_back(prices[i]);
                else{
                    v.push_back((prices[i]-st.top()));
                }
            }
            st.push(prices[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};