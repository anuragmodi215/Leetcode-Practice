// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int>adj[], vector<int>&visited, vector<int>&dfsVisited){
        visited[node]=1;
        dfsVisited[node]=1;
        
        for(auto neig: adj[node]){
            if(!visited[neig]){
                // visited[neig]=1;
                // dfsVisited[neig]=1;
                bool x = dfs(neig,adj,visited,dfsVisited);
                if(x) return true;
            }
            else if(dfsVisited[neig]){
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V+1);
        vector<int>dfsVisited(V+1);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                bool ans = dfs(i,adj,visited,dfsVisited);
                if(ans)return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends