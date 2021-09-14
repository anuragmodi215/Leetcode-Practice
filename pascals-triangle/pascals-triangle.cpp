class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>>v(rows);
        if(rows==0) return v;
        
        for(int i=0; i<rows; i++){
           v[i].resize(i+1);
           v[i][0] = v[i][i] = 1;
            
            for(int j=1; j<i;j++){
                v[i][j] = v[i-1][j]+v[i-1][j-1];                
            }
        }
        return v;
    }
};