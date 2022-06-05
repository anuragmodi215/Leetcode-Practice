class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    bool isValid(vector<vector<int>>& grid, int x, int y, vector<vector<int>>&visited){
        int n = grid.size();
        int m = grid[0].size();
        if(x>=0 and y>=0 and x<n and y<m and grid[x][y]==1 and !visited[x][y]) return true;
        return false;
    }
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>&visited){
        int area=1;
        visited[i][j]=1;
        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(grid,x,y,visited)){
                area = area+dfs(grid,x,y,visited);
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 and !visited[i][j]){
                    maxArea = max(maxArea,dfs(grid,i,j,visited));
                }
            }
        }
        return maxArea;
    }
};