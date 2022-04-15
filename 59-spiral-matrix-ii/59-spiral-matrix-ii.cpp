class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val = 1;
        vector<vector<int>> matrix(n,vector<int>(n));
        int left=0,top=0;
        int bottom = n-1, right = n-1;
        int dir = 1;
        while(left<=right and top<=bottom){
            if(dir == 1){
                for(int i=left; i<=right; i++){
                    matrix[top][i]=val++;
                }
                top++;
                dir = 2;
            }
            else if(dir == 2){
                for(int i=top; i<=bottom; i++){
                    matrix[i][right]=val++;
                }
                right--; dir = 3;
            }
            else if(dir == 3){
                for(int i=right; i>=left; i--){
                    matrix[bottom][i]=val++;
                }
                bottom--; dir = 4;
            }
            else if(dir == 4){
                for(int i=bottom; i>=top; i--){
                    matrix[i][left]=val++;
                }
                left++;
                dir = 1;
            }
        }
        return matrix;
    }
};