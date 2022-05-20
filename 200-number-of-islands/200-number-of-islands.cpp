class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    bool isValid(int i, int j, vector<vector<char>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i>=0 and j>=0 and i<n and j<m and grid[i][j]=='1')
        {
            return true;
        }
        return false;
    }
    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j]='0';
        for(int k=0; k<4; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(isValid(x,y,grid)){
                dfs(x,y,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};