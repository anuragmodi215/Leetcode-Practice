class Solution {
public:
    bool dfs(int node, unordered_map<int,vector<int>>&adj, vector<int>&visited, vector<int>&dfsVisited,vector<int>&ans){
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto neig: adj[node]){
            if(!visited[neig]){
                bool foundCycle = dfs(neig,adj,visited,dfsVisited,ans);
                if(foundCycle) return true;
            }
            else if(dfsVisited[neig]){
                return true;
            }
        }
        dfsVisited[node] = 0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>visited(numCourses+1);
        vector<int>dfsVisited(numCourses+1);
        vector<int>ans;
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool foundCycle = dfs(i,adj,visited,dfsVisited,ans);
                if(foundCycle) return {};
            }
        }
        return ans;
    }
};