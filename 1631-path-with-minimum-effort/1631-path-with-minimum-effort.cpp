class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>effort(n,vector<int>(m,INT_MAX));
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>>pq;
        
        pq.push(make_tuple(0,0,0));
        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()){
            auto[prevEffort, prevRow, prevCol] = pq.top();
            pq.pop();
            if(prevRow==n-1 and prevCol==m-1) return prevEffort;
            if(prevEffort>effort[prevRow][prevCol])continue;
            for(int i=0; i<4; i++){
                int newRow = prevRow+dir[i].first;
                int newCol = prevCol+dir[i].second;
                
                if(newRow<n and newRow>=0 and newCol<m and newCol>=0){
                    int newEffort = max(prevEffort, abs(heights[prevRow][prevCol]-heights[newRow][newCol]));
                    
                    if(newEffort<effort[newRow][newCol]){
                        effort[newRow][newCol] = newEffort;
                        pq.push(make_tuple(newEffort,newRow,newCol));
                    }
                }
            }
        }
        return 0;
    }
};