class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        
        int rows = a.size();
        int cols = a[0].size();
        
        for(int i=0; i<rows; i++){
            for(int j=i; j<cols; j++){
                int temp = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = temp;
            }
        }
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols/2; j++){
                int temp = a[i][j];
                a[i][j] = a[i][cols-1-j];
                a[i][cols-1-j]=temp;
            }
        }
        
    }
};