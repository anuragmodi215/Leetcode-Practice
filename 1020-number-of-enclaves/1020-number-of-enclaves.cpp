class Solution {
public:
    bool isValid(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<n and j<m and i>=0 and j>=0 and grid[i][j]==1){
            return true;
        }
        return false;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid){
        vector<pair<int,int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0; k<4; k++){
            grid[i][j]=-1;
            int dx = i+dir[k].first;
            int dy = j+dir[k].second;
            if(isValid(dx,dy,grid)){
                dfs(dx,dy,grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n ; i++){
            int j=0;
            if(isValid(i,j,grid)){
                dfs(i,j,grid);
            }
            j=m-1;
            if(isValid(i,j,grid)){
                dfs(i,j,grid);
            }
        }
        for(int j=0; j<m; j++){
            int i=0;
            if(isValid(i,j,grid)){
                dfs(i,j,grid);
            }
            i=n-1;
            if(isValid(i,j,grid)){
                dfs(i,j,grid);
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};