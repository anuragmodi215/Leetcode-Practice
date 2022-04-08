class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int x=1;
        int n = arr.size();
        for(int i=1; i<arr[n-1]; i++){
            if(!binary_search(arr.begin(),arr.end(),x)){
                k--;
                if(k==0) return x;
            }
            x++;
        }
        return arr[n-1]+k;
    }
};