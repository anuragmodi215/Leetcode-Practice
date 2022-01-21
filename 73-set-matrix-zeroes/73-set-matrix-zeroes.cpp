class Solution {
public:
    void MakeItZero(vector<vector<int>>& matrix, int n, int m, pair<int,int> ind){
        int i=ind.first;
        int j=ind.second;
        int forward,backward;
        forward=backward=i;
        while(forward<n or backward>=0){
            if(forward<n) matrix[forward++][j]=0;
            if(backward>=0) matrix[backward--][j]=0;
        }
        forward=backward=j;
        while(forward<m or backward>=0){
            if(forward<m) matrix[i][forward++]=0;
            if(backward>=0) matrix[i][backward--]=0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        set<pair<int,int>>set;
        pair<int,int>index;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j]==0){
                    index.first=i;
                    index.second=j;
                    set.insert(index);
                }
            }
        }
        
        for(auto i:set){
            pair<int,int>ind=i;
            MakeItZero(matrix,rows,cols,ind);
        }
    }
};