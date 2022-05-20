class Solution {
public:
    bool dfs(int src, int des,unordered_map<int,vector<int>>&adj, vector<int>&visited){
        if(src==des) return true;
        visited[src]=true;
        for(auto neighbour:adj[src]){
            if(!visited[neighbour]){
                bool x = dfs(neighbour,des,adj,visited);
                if(x) return x;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(n,0);
        return dfs(source,destination,adj,visited);
    }
};