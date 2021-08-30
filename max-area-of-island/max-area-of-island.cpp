class Solution {
public:
    int MaxArea(vector<vector<int>>& grid, int i, int j,int rows, int cols){
        if(i<0 or j<0 or i>=rows or j>=cols or grid[i][j]==2 or grid[i][j]==0) return 0;
        
        grid[i][j] = 2;
        
        return 1+MaxArea(grid,i+1,j,rows,cols)+MaxArea(grid,i,j+1,rows,cols)+MaxArea(grid,i-1,j,rows,cols)+MaxArea(grid,i,j-1,rows,cols);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    max_area = max(max_area,MaxArea(grid,i,j,rows,cols));
                }
            }
        }
        return max_area;
    }
};