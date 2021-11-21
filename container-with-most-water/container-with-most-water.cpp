class Solution {
public:
    int maxArea(vector<int>& height) {
        int water_trapped=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int temp_water = (j-i)*min(height[i],height[j]);
            water_trapped = max(water_trapped,temp_water);
            if(height[i]<height[j]) i++;
            else j--;
        }
        return water_trapped;
    }
};