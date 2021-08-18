class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l=0, r=height.size()-1;
        int area=0,x=INT_MIN;
        while(l<r){
            int lh = height[l];
            int rh = height[r];
            
            area = min(lh,rh)*abs(l-r);
            x=max(area,x);
            if(lh>rh) r--;
            else l++;
        }
        return x;
    }
};