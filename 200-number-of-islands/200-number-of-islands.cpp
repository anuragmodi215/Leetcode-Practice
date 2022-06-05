class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    bool isValid(vector<vector<char>>& grid,vector<vector<int>>&visited, int i, int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<n and j<m and i>=0 and j>=0 and grid[i][j]=='1' and !visited[i][j]) return true;
        return false;
    }
    int dfs(vector<vector<char>>& grid,vector<vector<int>>&visited, int i, int j){
        for(int k=0; k<4; k++){
            visited[i][j]=1;
            int newX=i+dx[k];
            int newY=j+dy[k];
            if(isValid(grid,visited,newX,newY)){
                dfs(grid,visited,newX,newY);
            }
        }
        return 1;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' and !visited[i][j]){
                    cnt+=dfs(grid,visited,i,j);
                }
            }
        }
        return cnt;
    }
};