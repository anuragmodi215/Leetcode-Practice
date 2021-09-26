class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>lmax(n); 
        vector<int>rmax(n);
        vector<int>water(n);
        int sum = 0;
        
        rmax[0] = height[0];
        for(int i=1; i<n; i++){
            rmax[i] = max(rmax[i-1], height[i]);
        }
        lmax[n-1] = height[n-1];
        
        for(int i=n-2; i>=0; i--){
            lmax[i]=max(lmax[i+1],height[i]);
        }
        for(int i=0; i<n; i++){
           water[i] = min(lmax[i],rmax[i]);
            water[i] = abs(water[i]-height[i]);
            sum = sum+water[i];
        }
        return sum;
    }
};