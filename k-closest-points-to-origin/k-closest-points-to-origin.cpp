class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,vector<int>>> pq;
        for(int i=0; i<n; i++){
            int x = pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({x,points[i]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};