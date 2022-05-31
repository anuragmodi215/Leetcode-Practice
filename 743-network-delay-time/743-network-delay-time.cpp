class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        
        vector<int>timeTaken(n+1,INT_MAX);
        timeTaken[k]=0;
        queue<pair<int,int>>q;
        q.push({k,0});
        
        while(!q.empty()){
            int frontNode = q.front().first;
            int prevTime = q.front().second;
            q.pop();
            for(auto neig: adj[frontNode]){
                int newTime = neig.second;
                int node = neig.first;
                if(timeTaken[node]>prevTime+newTime){
                    timeTaken[node] = prevTime+newTime;
                    q.push({node,timeTaken[node]});
                }
                
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(timeTaken[i]==INT_MAX) return -1;
            ans = max(ans,timeTaken[i]);
        }
        return ans;
    }
};