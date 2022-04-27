class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        for(int i=0; i<numRows; i++){
            vector<int>columns(i+1);
            columns[0]=1;
            columns[i]=1;
            v.push_back(columns);
        }

        for(int i=2; i<numRows; i++){
            for(int j=1; j<i; j++){
                v[i][j] = v[i-1][j-1]+v[i-1][j];
            }
        }
        return v;
    }
};