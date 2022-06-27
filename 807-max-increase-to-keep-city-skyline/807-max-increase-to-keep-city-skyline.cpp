class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>row(n);
        vector<int>col(n);
        int gridSum=0;
        for(int i=0; i<n; i++){
            int maxi = 0;
            for(int j=0; j<n; j++){
                gridSum+=grid[i][j];
                row[i] = max(row[i],grid[i][j]);
                col[i]=max(col[i],grid[j][i]);
            }
        }    
        int sum=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum = sum+min(row[i],col[j]);
            }
        }
        return sum-gridSum;
    }
};