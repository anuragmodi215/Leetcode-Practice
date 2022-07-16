class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int maxRight=0,maxLeft=0;
        int water=0;
        while(i<j){
            if(height[i]<height[j]){
                maxLeft = max(height[i],maxLeft);
                water+=(maxLeft-height[i]);
                i++;
            }
            else{
                maxRight = max(maxRight,height[j]);
                water+=(maxRight-height[j]);
                j--;
            }
        }
        return water;
    }
};