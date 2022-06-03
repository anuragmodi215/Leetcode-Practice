class NumMatrix {
public:
    //int d = 201;
    vector<vector<int>>v;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=1; j<m; j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j]+=matrix[i-1][j];
            }
        }
       for(auto i:matrix){
           v.push_back(i);
       }
        // for(auto i:v){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int temp = v[row2][col2];
        cout<<temp<<endl;
        int extra=0;
        //int leftTop= v[row1-1][col1-1];
        if(row1-1>=0 and col1-1>=0){
            extra-=v[row1-1][col1-1];
        }
         //int leftBottom = v[row2][col1-1];
        if(col1-1>=0){
            extra+= v[row2][col1-1];
        }
        if(row1-1>=0){
            extra+=v[row1-1][col2];
        }
        return temp-extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */