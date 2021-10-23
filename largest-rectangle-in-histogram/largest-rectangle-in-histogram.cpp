class Solution {
public:
    void NSL(vector<int>& heights,vector<int>&left,int n){
        stack<pair<int,int>> st;
        for(int i=0; i<n; i++){
            if(st.size()==0)left.push_back(-1);
            else if(st.size()>0 and st.top().first<heights[i]) left.push_back(st.top().second);
            else
            {
                while(st.size()>0 and st.top().first>=heights[i]) st.pop();
                if(st.size()==0)left.push_back(-1);
                else left.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        
    }
    
    void NSR(vector<int>& heights,vector<int>&right,int n){
        stack<pair<int,int>>st;
        for(int i=n-1; i>=0; i--){
            if(st.size()==0)right.push_back(n);
            else if(st.size()>0 and st.top().first<heights[i]) right.push_back(st.top().second);
            else{
                while(st.size()>0 and st.top().first>=heights[i]) st.pop();
                if(st.size()==0) right.push_back(n);
                else right.push_back(st.top().second);
            }
            st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left;
        vector<int>right;
        int n=heights.size();
        NSL(heights,left,n);
        NSR(heights,right,n);
        for(int i=0; i<n; i++) cout<<left[i]<<" ";
        cout<<endl;
        for(int i=0; i<n; i++) cout<<right[i]<<" ";
        vector<int>width(n);
        int area=0;
        for(int i=0; i<n; i++){
            width[i]=right[i]-left[i]-1;
            width[i]*=heights[i];
            area=max(area,width[i]);
        }
       // for(auto i:left) cout<<i<<" ";
        return area;
    }
};