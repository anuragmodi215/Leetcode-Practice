class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size()-1;
        int n = arr.size();
        if(n==1) return 0;
        for(right=n-1; right>=1; right--){
            if(arr[right]<arr[right-1])break;
        }
        
        int minLen = right;
        for(int i=0; i<n and i<right; i++){
            if(right==n or arr[i]<=arr[right]){
                minLen = min(minLen, right-i-1);
            }
            else right++;
            if(arr[i]>arr[i+1])break;
        }
        return minLen;
    }
};