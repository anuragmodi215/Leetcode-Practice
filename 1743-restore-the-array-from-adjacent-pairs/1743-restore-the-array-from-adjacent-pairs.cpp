class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>>&adj, unordered_map<int,bool>&visited, vector<int>&ans){
        visited[node] = 1;
        ans.push_back(node);
        for(auto neig:adj[node]){
            if(!visited[neig]){
                dfs(neig,adj,visited,ans);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>ans;
        int node=-1;
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>visited;
        for(int i=0; i<n; i++){
            mp[nums[i][0]]++;
            mp[nums[i][1]]++;
            int u = nums[i][0];
            int v = nums[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(auto i:mp){
            if(i.second==1){
               node = i.first;
               break;
            }
        }
        ans.push_back(node);
        visited[node] = 1;
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(i,adj,visited,ans);
            }
        }
        
        return ans;
    }
};