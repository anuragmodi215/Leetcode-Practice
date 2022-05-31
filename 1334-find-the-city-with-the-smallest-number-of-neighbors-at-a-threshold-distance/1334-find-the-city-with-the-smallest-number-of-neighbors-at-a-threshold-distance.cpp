class Solution {
public:
    static bool cmp(pair<int,int>a, pair<int,int>b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
        
//          if(p1.first != p2.first)
//         return p1.first < p2.first;
    
//     return p1.second > p2.second;
        
    }
    vector<pair<int,int>>ans;
    void bfs(int src, unordered_map<int,vector<pair<int,int>>>&adj, int n,int distanceThreshold){
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<int>distance(n,INT_MAX);
        distance[src]=0;
        while(!q.empty()){
            int frontNode = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(dis>distanceThreshold)continue;
            for(auto neig: adj[frontNode]){
                int node = neig.first;
                int d = neig.second;
                if(distance[node]>dis+d and dis+d<=distanceThreshold){
                    distance[node] = dis+d;
                    q.push({node,distance[node]});
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(i!=src and distance[i]<=distanceThreshold){
                cnt++;
            }
        }
        ans.push_back({cnt,src});
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
     
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int weig = edges[i][2];
            adj[u].push_back({v,weig});
            adj[v].push_back({u,weig});
        }
        for(int i=0; i<n; i++){
            bfs(i,adj,n,distanceThreshold);
        }
        // for(auto i:ans){
        //     cout<<"City "<<i.second<<"->"<<i.first<<endl;
        // }
        sort(ans.begin(),ans.end(),cmp);
        //  for(auto i:ans){
        //     cout<<"City "<<i.second<<"->"<<i.first<<endl;
        // }
        return ans[0].second;
    }
};