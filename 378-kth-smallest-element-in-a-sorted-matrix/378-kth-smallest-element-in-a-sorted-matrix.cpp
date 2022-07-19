class Solution {
public:
    int cntSmallerThanEqual(vector<int>&v, int target){
        int low=0,high = v.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(v[mid]<=target){
                low = mid+1;
            }
            else high = mid-1;
        }
        return low;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low =matrix[0][0];
        int high = matrix[n-1][m-1];
        while(low<=high){
            int mid = low+(high-low)/2;
            int cnt=0;
            for(int i=0; i<n; i++){
                cnt+=cntSmallerThanEqual(matrix[i],mid);
            }
            if(cnt<k){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};