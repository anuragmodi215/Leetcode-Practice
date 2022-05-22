class Solution {
public:
    bool dfs(int node, unordered_map<int,vector<int>>&adj, unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,vector<int>&notTake){
        //cout<<node<<endl;
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool x = dfs(neighbour,adj,visited,dfsVisited,notTake);
                if(x){
                    notTake[node] = true;
                    return true;
                }
            }
            else{
                if(dfsVisited[neighbour]){
                    notTake[node] = true;
                    return true;
                }
            }
        }
        
        dfsVisited[node] = 0;
        return false;
    }
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        vector<int> notTake(n,0);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        // for(auto i:adj){
        //     cout<<i.first<<"->";
        //     for(auto j:i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bool x = dfs(i,adj,visited, dfsVisited, notTake);   
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(!notTake[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};