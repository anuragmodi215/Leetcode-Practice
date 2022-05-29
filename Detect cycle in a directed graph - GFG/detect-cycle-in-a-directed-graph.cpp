// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>indegree(v);
        vector<int>ans;
        queue<int>q;
        for(int i=0; i<v; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0; i<v; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int frontNode = q.front();
            ans.push_back(frontNode);
            q.pop();
            for(auto neig:adj[frontNode]){
                indegree[neig]--;
                if(indegree[neig]==0){
                    q.push(neig);
                }
            }
        }
        
        if(ans.size()==v){
            return false;
        }
        return true;
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