class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int ans=1;
        // for(auto i:points){
        //     cout<<i[0]<<","<<i[1]<<" ";
        // }
        int n = points.size();
      
        int prev = points[0][1];
        for(int i=1; i<n; i++){
           if(prev>=points[i][0]){
               continue;
           }
           else{
               ans++;
               prev = points[i][1];
           }   
        }
        return ans;
    }
};