class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i=1; 
        int n=arr.size();
        int ans=0;
        if(n<3) return ans;
        while(i<n){
            int incr=0;
            int decr=0;
            while(i<n and arr[i]>arr[i-1]) i++,incr++;
            while(i<n and arr[i]<arr[i-1]) i++,decr++;
            if(incr>0 and decr>0)
            ans = max(ans,incr+decr+1);
            while(i<n and arr[i]==arr[i-1]) i++;
        }
        return ans;
    }
};