class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int start, int end, vector<vector<int>>& graph, vector<int>path){
        path.push_back(start);
        if(start == end){
            ans.push_back(path);
        }
        for(auto neig : graph[start]){
            dfs(neig,end,graph,path);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        int n = graph.size();
        dfs(0,n-1,graph,path);
        return ans;
        
    }
};