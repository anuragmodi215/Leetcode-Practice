class Solution {
public:
    bool binarySearch(vector<int>v,int target){
        int strt=0,end=v.size()-1;
        int mid;
        while(strt<=end){
            mid=strt+(end-strt)/2;
            if(v[mid]==target) return true;
            else if(v[mid]>target) end=mid-1;
            else strt=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[i][m-1]>=target and matrix[i][0]<=target){
                bool ans=binarySearch(matrix[i],target);
                if(ans) return ans;
            }
        }
        return false;
    }
};