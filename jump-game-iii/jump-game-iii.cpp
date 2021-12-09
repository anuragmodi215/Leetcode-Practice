class Solution {
public:
    
    bool helper(vector<int>& arr, int ind,int n,vector<int>&visited){
        if(ind<0 or ind>=n) return false;
        if(visited[ind]==1) return false;
        visited[ind]=1;
        if(arr[ind]==0) return true;

        bool ans1=helper(arr,ind+arr[ind],n,visited);

        bool ans2=helper(arr,ind-arr[ind],n,visited);

        return (ans1 or ans2);
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>visited(arr.size(),0);
        return helper(arr,start,arr.size(),visited);
    }
};