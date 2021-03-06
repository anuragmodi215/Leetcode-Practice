class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans;
        stack<pair<int,int>>st;
        for(int i=n-1; i>=0; i--){
            if(st.size()==0) ans.push_back(0);
            
            else if(st.size()>0 and st.top().first>temperatures[i]){
                ans.push_back(st.top().second-i);
            }
            else if(st.size()>0 and st.top().first<=temperatures[i]){
                while(st.size()>0){
                    if(st.top().first>temperatures[i]){
                        ans.push_back(st.top().second-i);
                        break;
                    }
                    else st.pop();
                }
                if(st.size()==0) ans.push_back(0);
            }
            st.push({temperatures[i],i});
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};