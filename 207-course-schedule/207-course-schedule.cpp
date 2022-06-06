class Solution {
public:
    bool dfs(int node,unordered_map<int,vector<int>>&adj,vector<int>&visited,vector<int>&dfsVisited){
        visited[node] = 1;
        dfsVisited[node]=1;
        for(int neig : adj[node]){
            if(!visited[neig]){
                bool x = dfs(neig, adj, visited, dfsVisited);
                if(x) return true;
            }
            else{
                if(dfsVisited[neig]==1) return true;
            }
        }
        dfsVisited[node] = 0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) { 
        unordered_map<int,vector<int>>adj;
        int n = prerequisites.size();
        if(n==0) return true;
        vector<int>visited(numCourses+1);
        vector<int>dfsVisited(numCourses+1);
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