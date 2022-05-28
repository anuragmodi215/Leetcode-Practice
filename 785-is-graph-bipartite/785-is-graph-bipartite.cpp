class Solution {
public:
    bool bfs(int node,vector<vector<int>>& graph,vector<int>&colour){ 
        queue<int>q;
        q.push(node);
        colour[node] = 1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto neig:graph[frontNode]){
                if(colour[neig]==-1){
                    colour[neig] = 1-colour[frontNode];
                    q.push(neig);
                }
                else{
                    if(colour[neig]==colour[frontNode]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int,vector<int>>adj;
        vector<int>colour(n,-1);
        
        for(int i=0; i<n; i++){
            if(colour[i]==-1){
                bool x = bfs(i,graph,colour);
                if(x==false) return false;
            }
        }
        return true;
    }
};