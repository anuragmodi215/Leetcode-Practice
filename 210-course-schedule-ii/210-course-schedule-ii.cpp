class Solution {
public:
    bool topologicalSort(int node, unordered_map<int,vector<int>>&adj, unordered_map<int,bool>&visited,stack<int>&stack,unordered_map<int,bool>&dfsVisited){
        visited[node] = 1;
        dfsVisited[node] = 1;
        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                bool x = topologicalSort(neighbour,adj,visited,stack,dfsVisited);
                if(x) return true;
            }
            else if(dfsVisited[neighbour]){
                return true;
            }
        }
        dfsVisited[node]=0;
        stack.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsVisited;
        stack<int>stack;
        vector<int>ans;
        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                bool  x = topologicalSort(i,adj,visited,stack,dfsVisited);
                if(x) return {};
            }
        }
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }
        // if(ans.size()==0){
        //     ans.push_back(0);
        // }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};