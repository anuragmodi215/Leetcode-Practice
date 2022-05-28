class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&colour){ 
        if(colour[node]==-1)
        {
            colour[node] = 1;
        }
        for(auto neig: graph[node]){
            if(colour[neig]==-1){
                colour[neig] = 1-colour[node];
                bool x = dfs(neig,graph,colour);
                if(!x){
                    return false;
                }
            }
            else if(colour[neig]==colour[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //unordered_map<int,vector<int>>adj;
        vector<int>colour(n,-1);
        
        for(int i=0; i<n; i++){
            if(colour[i]==-1){
                bool x = dfs(i,graph,colour);
                if(x==false) return false;
            }
        }
        return true;
    }
};