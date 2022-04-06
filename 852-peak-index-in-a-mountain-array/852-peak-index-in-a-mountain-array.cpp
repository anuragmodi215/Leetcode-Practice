class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int ind=0;
        
        for(int i=1; i<n; i++){
            if(i+1<n and arr[i]>arr[i-1] and arr[i]>arr[i+1]) ind = i;
        }
        
        return ind;
    }
};