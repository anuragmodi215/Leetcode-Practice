class Solution {
public:
    void helper(vector<vector<int>>& matrix,vector<pair<int,int>>&zeros,int n, int m){
        int zerosSize = zeros.size();
        for(int k=0; k<zerosSize; k++){
            int row = zeros[k].first;
            int col = zeros[k].second;
            
            for(int i=row; i<n; i++){
                matrix[i][col] = 0;
            }
            for(int i=row; i>=0; i--){
                matrix[i][col] = 0;
            }
        
            for(int j=col; j<m; j++)
                matrix[row][j] = 0;
        
            for(int j=col; j>=0; j--)
                matrix[row][j] = 0;
        }

    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int,int>> zeros;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    zeros.push_back({i,j});
                }
            }
        }
        helper(matrix,zeros,n,m);
    }
};