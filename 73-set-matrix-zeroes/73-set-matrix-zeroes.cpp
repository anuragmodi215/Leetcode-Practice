class Solution {
public:
    void helper(vector<vector<int>>& matrix,vector<pair<int,int>>&zeros,int n, int m){
        int zerosSize = zeros.size();
        for(int k=0; k<zerosSize; k++){
            int row = zeros[k].first;
            int col = zeros[k].second;
            
            int forward = row;
            int backward = row;
            
            while(forward<n or backward>=0){
                if(forward<n) matrix[forward++][col] = 0;
                if(backward>=0) matrix[backward--][col] = 0;
            }
            
            forward = col;
            backward = col;
            while(forward<m or backward>=0){
                if(forward<m) matrix[row][forward++] = 0;
                if(backward>=0) matrix[row][backward--] = 0;
            }
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