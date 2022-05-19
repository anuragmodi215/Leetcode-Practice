class Solution {
public:
    bool dfs(int node, unordered_map<int,vector<int>>&adj, unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited){
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool x = dfs(neighbour,adj,visited,dfsVisited);
                if(x) return true;
            }
            else{
                if(dfsVisited[neighbour]) return true;
            }
        }
        dfsVisited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool x = dfs(i,adj,visited,dfsVisited);
                if(x) return false;
            }
        }
        return true;
    }
};