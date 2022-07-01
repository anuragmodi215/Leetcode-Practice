class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isSafe(int i, int j, vector<vector<char>>& grid,vector<vector<int>>&visited){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=0 and j>=0 and i<n and j<m and !visited[i][j] and grid[i][j]=='1') return 1;
        return 0;
    }
    int cntIsland(int i, int j, vector<vector<char>>& grid, vector<vector<int>>&visited){
        for(int k=0; k<4; k++){
            visited[i][j] = 1;
            int x = i+dx[k];
            int y = j+dy[k];
            if(isSafe(x,y,grid,visited)){
                cntIsland(x,y,grid,visited);
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
                if(!visited[i][j] and grid[i][j]=='1'){
                    cnt=cnt+cntIsland(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};