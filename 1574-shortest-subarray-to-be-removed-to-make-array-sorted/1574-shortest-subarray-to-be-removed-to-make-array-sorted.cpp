class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
       
        int r;
        int n = arr.size();
        for(r=n-1; r>=1; r--){
            if(arr[r]<arr[r-1])break;
        }
        int ans = r;
        for(int i=0; i<n and i<r; i++){
            if(r==n or arr[i]<=arr[r]){
                ans = min(ans,(r-i-1));
            }
            else r++;
            
            if(arr[i]>arr[i+1])break;
        }
        return ans;
    }
};