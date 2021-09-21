class StockSpanner {
    stack<pair<int,int>> st;
    int i;
public:
    StockSpanner() {
     i=-1;
    }
    
    int next(int price) {
        i++;
        int ans;
        if(st.size()==0){
        ans = i+1;
        st.push({price,i});
         return ans;
        }
        else if(st.size()>0 and st.top().first>price){
            ans =  i-st.top().second; 
            st.push({price,i});
            return ans;
        } 
        
        else{
            while(st.size()>0 and st.top().first<=price) st.pop();
            
            if(st.size()==0){
                ans = i+1;
                st.push({price,i});
                return ans;
            } 
            
            else{
                ans =  i-st.top().second;
                st.push({price,i});
                return ans;
            }
        }
       // st.push({price,i});
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */