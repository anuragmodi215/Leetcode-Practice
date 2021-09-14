class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();
        if(rows*cols != r*c){
            return mat;
        }
        vector<vector<int>>v(r,vector<int>(c));
        int strtR=0;
        int strtC=0;
        for(int i=0; i<rows; i++){
           // if(strtR<r){
                for(int j=0; j<cols; j++){
                    if(strtC==c){
                        strtR++;
                        strtC=0;
                    }
                    v[strtR][strtC]=mat[i][j];
                    strtC++;
                }
           // }
        }
        return v;
    }
};