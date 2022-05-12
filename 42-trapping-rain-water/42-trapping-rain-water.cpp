class Solution {
public:
    int trap(vector<int>& height) {
        int maxRight=0,maxLeft=0,i=0,j=height.size()-1;
        int water=0;
        
        while(i<j){
            if(height[i]<=height[j]){
                maxLeft = max(maxLeft,height[i]);
                water = water+(maxLeft-height[i]);
                i++;
            }
            else{
                maxRight = max(maxRight,height[j]);
                water = water+(maxRight-height[j]);
                j--;
            }
        }
        return water;
    }
};